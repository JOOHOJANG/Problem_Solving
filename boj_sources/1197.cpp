#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>>v;
bool vis[10001];
int ans;
struct compare {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};
priority_queue<pii, vector<pii>, compare> pq;
​
void solve() {
    pq.push({ 1, 0 });
    while (!pq.empty()) {
        pii aa = pq.top(); pq.pop();
        if (vis[aa.first])continue;
        vis[aa.first] = true;
        ans += aa.second;
        for (auto k : v[aa.first]) {
            if (!vis[k.first])pq.push(k);
        }
    }
​
    cout << ans;
}
​
​
int n, m;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int a, b, c;
    v.resize(n + 1);
    for (int i = 0; i <m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }
​
    solve();
}
