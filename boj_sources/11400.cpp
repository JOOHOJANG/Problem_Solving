#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;
vector<vector<int>>v;
vector<pair<int, int>> vv;
int vis[1000001];
int V, E;
int a, b;
int dfs(int here, int parent) {
    vis[here] = ++cnt;
    int ret = vis[here];
    for (auto next : v[here]) {
        if (next == parent) continue;
​
        if (vis[next]) {
            ret = min(vis[next], ret);
            continue;
        }
​
        int prev = dfs(next, here);
        if (prev > ret) {
            vv.push_back(make_pair(min(here, next), max(here, next)));
        }
​
        ret = min(prev, ret);
    }
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
    for (int i = 1; i <= V; i++)if (!vis[i])dfs(i, 0);
    cout << vv.size() << "\n";
    sort(vv.begin(), vv.end());
    for (int i = 0; i < vv.size(); i++) {
        cout << vv[i].first << " " << vv[i].second << "\n";
    }
}
