#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100000000
using namespace std;
typedef pair<int, int> pii;
int n, m, st, dest;
vector<vector<pii>>v;
vector<vector<pii>>vv;
bool vis[501][501];
int dist[501];
struct compare {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};
void set() {
    memset(vis, false, sizeof(vis));
    v.clear(); vv.clear(); v.resize(0); vv.resize(0);
}
void find(int st) {
    priority_queue<pii, vector<pii>, compare>pq;
    for (int i = 0; i < 501; i++)dist[i] = MAX;
    dist[st] = 0;
​
    pq.push({ st, 0 });
    while (!pq.empty()) {
​
        pii a = pq.top(); pq.pop();
        if (dist[a.first] < a.second)continue;
​
        for (int i = 0; i < v[a.first].size(); i++) {
            int next = v[a.first][i].first;
            int val = v[a.first][i].second + dist[a.first];
            if (vis[a.first][next]) continue;
            if (dist[next] > val) {
                dist[next] = val;
                pq.push({ next, val });
            }
        }
    }
}
void bfs(int dest) {
    queue<int> q;
    q.push(dest);
    while (!q.empty()) {
        int a = q.front(); q.pop();
        if (a == st) continue;
​
        for (int i = 0; i < vv[a].size(); i++) {
            int prev = vv[a][i].first;
            if (dist[prev] + vv[a][i].second == dist[a]) {
                vis[prev][a] = true;
                q.push(prev);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (1) {
        set();
        cin >> n >> m;
        v.resize(m + 1);
        vv.resize(m + 1);
        if (!n && !m) return 0;
        cin >> st >> dest;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({ b,c });
            vv[b].push_back({ a,c });
        }
        find(st);
        bfs(dest);
        find(st);
        if (dist[dest] == MAX) cout << -1 << "\n";
        else cout << dist[dest] << "\n";
    }
}
