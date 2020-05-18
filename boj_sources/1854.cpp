#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> pii;
int n, m, k;
vector<vector<pii>>v;
priority_queue<int>dist[1001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> n >> m >> k;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }
    priority_queue<pii, vector<pii>, greater<>>pq;
    dist[1].push(0);
    pq.push({ 1, 0 });
    while (!pq.empty()) {
        int here = pq.top().first;
        int cost = pq.top().second; pq.pop();
​
        for (int i = 0; i < v[here].size(); i++) {
            int next = v[here][i].first;
            int nextcost = v[here][i].second;
​
            if (dist[next].size() < k) {
                dist[next].push(nextcost + cost);
                pq.push({ next, cost + nextcost });
            }
            else if (dist[next].top() > cost + nextcost) {
                dist[next].pop();
                dist[next].push(cost + nextcost);
                pq.push({ next, cost + nextcost });
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i].size() == k)cout << dist[i].top() << "\n";
        else cout << -1 << "\n";
    }
}
