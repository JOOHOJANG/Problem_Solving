#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
​
vector<vector<int>>v, scc, vv;
queue<int> q;
int order[500001];
int n, m;
int a, b, c;
bool fin[500001];
int dfn[500001];
int sccnum[500001];
int initcash[500001];
long long last[500001];
long long scccash[500001];
int vis[500001];
vector<int> st;
int cnt;
int sccnumt;
int stp, rest;
bool check[500001];
int indeg[500001];
long long ans;
​
void ddfs(int cur) {
    vis[cur] = 1;
    for (auto next : vv[cur]) {
        indeg[next]++;
        if (vis[next])continue;
        ddfs(next);
    }
}
​
int dfs(int cur) {
    dfn[cur] = ++cnt;
    st.push_back(cur);
    int res = dfn[cur];
​
    for (auto next : v[cur]) {
        if (!dfn[next]) {
            res = min(res, dfs(next));
        }
        else if (!fin[next]) {
            res = min(res, dfn[next]);
        }
    }
​
    if (res == dfn[cur]) {
        scc.push_back({});
        while (1) {
            int aa = st.back(); st.pop_back();
            fin[aa] = true;
            sccnum[aa] = sccnumt;
            scc[sccnumt].push_back(aa);
            if (aa == cur) break;
        }
        sccnumt++;
​
    }
    return res;
}
​
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i])dfs(i);
    }
    for (int i = 1; i <= n; i++)cin >> initcash[i];
    cin >> stp;
​
​
    for (int i = 0; i < sccnumt; i++) {
        for (auto k : scc[i]) {
            scccash[i] += initcash[k];
        }
    }
    vv.resize(sccnumt + 1);
    for (int i = 1; i <= n; i++) {
        for (auto k : v[i]) {
            if (sccnum[i] != sccnum[k]) {
                vv[sccnum[i]].push_back(sccnum[k]);
            }
        }
    }
    cin >> rest;
    for (int i = 1; i <= rest; i++) {
        cin >> a;
        check[sccnum[a]] = true;
    }
    ddfs(sccnum[stp]);
​
    for (int i = 0; i < sccnumt; i++) {
        if (!indeg[i] && vis[i]) {
            q.push(i);
            last[i] = scccash[i];
        }
    }
    while (!q.empty()) {
        int aa = q.front(); q.pop();
        for (auto next : vv[aa]) {
            last[next] = max(last[next], last[aa] + scccash[next]);
            if (--indeg[next] == 0) q.push(next);
        }
    }
    for (int i = 0; i < sccnumt; i++) {
        if (check[i]) {
            ans = max(ans, last[i]);
        }
    }
​
    cout << ans;
}
