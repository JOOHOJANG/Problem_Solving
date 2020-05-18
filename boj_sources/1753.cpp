#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 1000000000
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> v;
int V, E;
int a, b, c;
int st;
int dist[20001];
struct compare {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};
priority_queue<pii, vector<pii>, compare>pq;
​
void solve(int st) {
    pq.push({ st, 0 });
​
    while (!pq.empty()) {
​
        pii temp = pq.top(); pq.pop();
        if (dist[temp.first] < temp.second) continue;
​
        for (auto next : v[temp.first]) {
            int ver = next.first;
            int val = next.second + temp.second;
            if (dist[ver] > val) {
                dist[ver] = val;
                pq.push({ ver, val });
            }
        }
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> V >> E >> st;
    v.resize(V + 1);
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
    }
    for (int i = 0; i <= 20000; i++) dist[i] = MAX;
    solve(st);
    for (int i = 1; i <= V; i++) {
        if (i == st)cout << 0 << "\n";
        else if (dist[i] == MAX)cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}
