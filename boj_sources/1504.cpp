#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define INF 1900000000
#define INT_MAX_ 1900000000
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>>v;
int N, E;
int s1, s2;
int OneToV1, OneToV2, V1ToN, V2ToN, V1ToV2;
int n, e;
int dist[801];
struct compare {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};
void dijkstra(int st) {
    priority_queue<pii, vector<pii>, compare>pq;
    for (int i = 0; i <= 800; i++) dist[i] = INF;
    dist[st] = 0;
    pq.push({ st, 0 });
    while (!pq.empty()) {
        int here = pq.top().first;
        int val = pq.top().second;
        pq.pop();
        if (dist[here] < val) continue;
        for (auto k : v[here]) {
            int next = k.first;
            int dis = k.second;
            if (dist[next] > val + dis) {
                dist[next] = val + dis;
                pq.push({ next, val + dis });
            }
        }
    }
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> n >> e;
    v.resize(n + 1);
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }
    cin >> s1 >> s2;
    dijkstra(1);
​
    OneToV1 = dist[s1];
    OneToV2 = dist[s2];
    if (OneToV1 >= INT_MAX_ && OneToV2 >= INT_MAX_) {
        cout << -1 << endl;
        return 0;
    }
​
    dijkstra(n);
​
    V1ToN = dist[s1];
    V2ToN = dist[s2];
​
    if (V1ToN >= INT_MAX_ && V2ToN >= INT_MAX_) {
        cout << -1 << endl;
        return 0;
    }
​
    dijkstra(s1);
​
    V1ToV2 = dist[s2];
​
    if (V1ToV2 >= INT_MAX_) {
        cout << -1 << endl;
        return 0;
    }
​
    int root1 = -1;
    int root2 = -1;
    if (!(OneToV1 >= INT_MAX_ || V1ToV2 >= INT_MAX_ || V2ToN >= INT_MAX_)) {
        root1 = OneToV1 + V1ToV2 + V2ToN;
    }
    if (!(OneToV2 >= INT_MAX_ || V1ToV2 >= INT_MAX_ || V1ToN >= INT_MAX_)) {
        root2 = OneToV2 + V1ToV2 + V1ToN;
    }
​
    if (root1 == -1 && root2 == -1) {
        cout << -1 << endl;
    }
    else {
        cout << min(root1, root2) << endl;
    }
​
​
    return 0;
}
