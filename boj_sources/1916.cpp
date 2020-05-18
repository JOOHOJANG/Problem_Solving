#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define INF 2100000000
using namespace std;
typedef pair<int, int> pii;
struct compare {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};
vector<vector<pii>>v;
int n, m;
int st, dest;
int dist[1001];
​
void solve(int st) {
    for (int i = 0; i < 1001; i++) dist[i] = INF;
    priority_queue<pii, vector<pii>, compare>pq;
    pq.push({ st, 0 });
    dist[st] = 0;
    while (!pq.empty()) {
        pii tmp = pq.top(); pq.pop();
        if (dist[tmp.first] < tmp.second) continue;
​
        for (auto next : v[tmp.first]) {
            int idx = next.first;
            int val = next.second + tmp.second;
            if (dist[idx] > val) {
                dist[idx] = val;
                pq.push({ idx, val });
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
    }
    cin >> st >> dest;
​
    solve(st);
    cout << dist[dest];
}
