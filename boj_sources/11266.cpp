#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;
vector<vector<int>>v;
vector<pair<int, int>> vv;
int vis[1000001];
int low[1000001];
int V, E;
int a, b;
int dfs(int here, int parent) {
    vis[here] = ++cnt;
    int ret = vis[here];
    int child = 0;
    for (auto next : v[here]) {
        if (vis[next]) {
            ret = min(vis[next], ret);
            continue;
        }
        child++;
        int prev = dfs(next, 0);
        if (!parent && prev >= vis[here]) low[here] = 1;
​
        ret = min(prev, ret);
    }
    if (parent) low[here] = child >= 2 ? 1 : 0;
    return ret;
}
​
int main() {
    cin >> V >> E;
    v.resize(V + 1);
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= V; i++)if (!vis[i])dfs(i, 1);
    int ans = 0;
    for (int i = 1; i <= V; i++)if (low[i]) ans++;
    cout << ans << "\n";
    for (int i = 1; i <= V; i++) if (low[i])cout << i << " ";
}
