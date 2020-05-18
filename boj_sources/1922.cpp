#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
​
typedef pair<int, int> pii;
vector<vector<pii>> v;
int vis[1001];
int sum;
​
struct compare {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};
priority_queue<pii, vector<pii>, compare>pq;
​
void solve() {
    vis[1] = 1;
    for (auto next : v[1]) {
        pq.push(next);
    }
    while (!pq.empty()) {
        pii tmp = pq.top(); pq.pop();
        if(!vis[tmp.first]){
            sum += tmp.second;
            vis[tmp.first] = 1;
            for (auto next : v[tmp.first]) {
                pq.push(next);
            }
        }
    }
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
​
    int n, m;
    int a, b, c;
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    solve();
    cout << sum;
}
