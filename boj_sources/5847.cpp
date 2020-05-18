#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
​
vector<vector<int>> v, scc;
vector<vector<int>> vv;
vector<int> st;
int sze, sccnumt; 
int cnt;
int n, m, t, s;
int sidx, tidx;
int sccnum[10001];
bool fin[10001];
int dfn[10001];
int vis[10001];
int last[10001];
int indeg[10001];
bool finflag;
int finans;
queue<int> q;
void ddfs(int cur, int val) {
    if (finflag) return;
    vis[cur] = 1;
    val += scc[cur].size();
    for (auto k : vv[cur]) {
        if (k == tidx) {
            finans = max(finans, val + (int)scc[k].size());
        }
        if (!vis[k])ddfs(k, val);
    }
    vis[cur] = 0;
}
int dfs(int cur) {
    dfn[cur] = ++cnt;
    st.push_back(cur);
    int res = dfn[cur];
    
    for (auto k : v[cur]) {
        if (!dfn[k]) {
            res = min(res, dfs(k));
        }
        else if (!fin[k]) {
            res = min(res, dfn[k]);
        }
    }
    if (res == dfn[cur]) {
        scc.push_back({});
        while (1) {
            int a = st.back(); st.pop_back();
            if (a == s) sidx = sccnumt;
            if (a == t) tidx = sccnumt;
            fin[a] = true;
            sccnum[a] = sccnumt;
            scc[sccnumt].push_back(a);
            if (a == cur) break;
        }
        sccnumt++;
    }
    return res;
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i])dfs(i);
    }
    vv.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto k : v[i]) {
            if (sccnum[i] != sccnum[k]) {
                vv[sccnum[i]].push_back(sccnum[k]);
                indeg[sccnum[k]]++;
            }
        }
    }
    if (tidx == sidx) {
        cout << scc[tidx].size();
    }
    else {
        ddfs(sidx, 0);
        if (finans == 0) {
            cout << 0;
        }
        else {
            q.push(sidx);
            last[sidx] = scc[sidx].size();
            while (!q.empty()) {
                int aa = q.front(); q.pop();
                for (auto k : vv[aa]) {
                    last[k] = max(last[k], (int)scc[k].size() + last[aa]);
                    if (--indeg[k] == 0) q.push(k);
                }
            }
            
            cout << last[tidx];
            
        }
    }
}
