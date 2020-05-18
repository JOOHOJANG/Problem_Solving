#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int icnt, n, k, a, b, c, cnt;
vector<vector<int>>v,vv, scc;
int indeg[2501], sccnum[2501];
int dfn[2501];
int sccnumt;
string str;
bool fin[2501];
int order[2501];
vector<int> st;
int dfs(int cur) {
​
    dfn[cur] = ++cnt;
    int res = dfn[cur];
    st.push_back(cur);
​
    for (auto k : v[cur]) {
        if (!dfn[k]) {
            res = min(res, dfs(k));
        }
        else if (!fin[k]) {
            res = min(res, dfn[k]);
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
    }
    return res;
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int u;
​
    map<string, int> ma;
    map<string, int>::iterator iter;
    v.resize(2501);
    for (int i = 0; i < n; ++i) {
        cin >> str >> k;
        iter = ma.find(str);
        if (iter == ma.end()) {
            ma[str] = icnt++;
            u = ma[str];
        }
        else {
            u = ma[str];
        }
        while (k--) {
            cin >> str;
            iter = ma.find(str);
            if (iter == ma.end()) {
                ma[str] = icnt++;
                b = ma[str];
            }
            else {
                b = ma[str];
            }
            v[b].push_back(u);
        }
    }
​
    for(int i = 0; i<icnt; i++){
        if (!dfn[i])dfs(i);
    }
    vv.resize(sccnumt);
    for (int i = 0; i < icnt; i++) {
        for (auto k : v[i]) {
            if (sccnum[k] != sccnum[i]) {
                indeg[sccnum[k]]++;
                vv[sccnum[i]].push_back(sccnum[k]);
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < sccnumt; i++) {
        if (!indeg[i])q.push(i);
    }
    for (int i = 0; i < sccnumt; i++) {
        int cur = q.front(); q.pop();
        order[i] = cur;
        for (auto k : vv[cur]) {
            if (--indeg[k] == 0) q.push(k);
        }
    }
​
    vector<long long>ans(icnt);
    fill(ans.begin(), ans.end(), 1);
​
    for (int i = 0; i < sccnumt; i++) {
        for (auto k : scc[order[i]]) {
            for (auto j : v[k]) {
                if (sccnum[k] != sccnum[j]) ans[j] += ans[k];
            }
        }
    }
    cin >> str;
    iter = ma.find(str);
    if (iter == ma.end())cout << 1;
    else cout << ans[ma[str]];
}
