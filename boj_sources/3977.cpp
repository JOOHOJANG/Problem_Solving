#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
vector<vector<int>>v, scc;
vector<int> st;
int n, t, a, b, m, sccnumt;
int cnt;
int indeg[100001];
int sccnum[100001];
int dfn[100001];
bool fin[100001];
void sett() {
    v.clear(); v.resize(0);
    cnt = 0;
    scc.clear(); scc.resize(0);
    sccnumt = 0;
    st.clear(); st.resize(0);
    memset(indeg, 0, sizeof(indeg));
    memset(sccnum, 0, sizeof(sccnum));
    memset(dfn, 0, sizeof(dfn));
    memset(fin, false, sizeof(fin));
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
    cin >> t;
    while (t--) {
        cin >> n >> m;
        v.resize(n);    
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            v[a].push_back(b);
        }
        for (int i = 0; i < n; i++) {
            if (!dfn[i])dfs(i);
        }
​
        for (int i = 0; i < n; i++) {
            for (auto k : v[i]) {
                if (sccnum[i] != sccnum[k]) {
                    indeg[sccnum[k]]++;
                }
            }
        }
        int ans = 0;
        int ch = 0;
        for (int i = 0; i < sccnumt; i++) {
            if (!indeg[i]) {
                ans++;
                ch = i;
            }
        }
        if (ans > 1) {
            cout << "Confused\n";
        }
        else {
            sort(scc[ch].begin(), scc[ch].end());
            for (int i = 0; i < scc[ch].size(); i++) {
                cout << scc[ch][i] << "\n";
            }
        }
        cout << "\n";
        sett();
    }
}
