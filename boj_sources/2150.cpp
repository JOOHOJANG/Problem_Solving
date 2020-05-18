#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
vector<vector<int>>v, vv, scc;
int vis[10001];
vector<int> st;
int sze;
​
void dfs(int cur) {
    vis[cur] = 1;
    for (auto k : v[cur]) {
        if (!vis[k]) dfs(k);
    }
    st.push_back(cur);
}
​
void rdfs(int cur) {
    vis[cur] = 1;
    for (auto k : vv[cur]) {
        if (vis[k]) continue;
        rdfs(k);
    }
    scc[sze].push_back(cur);
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, e;
    
    cin >> n >> e;
    v.resize(n + 1); vv.resize(n + 1); 
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        vv[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)if (!vis[i]) dfs(i);
    memset(vis, 0, sizeof(vis));
​
    while (!st.empty()) {
        int cur = st.back(); st.pop_back();
        if (vis[cur])continue;
        scc.push_back({});
        rdfs(cur);
        sze++;
    }
    for (int i = 0; i < scc.size(); i++) {
        sort(scc[i].begin(), scc[i].end());
    }
    sort(scc.begin(), scc.end());
    cout << scc.size() << "\n";
    for (int i = 0; i < scc.size(); i++) {
        for (int j = 0; j < scc[i].size(); j++) {
            cout << scc[i][j] << " ";
        }
        cout << -1 << "\n";
    }
}
