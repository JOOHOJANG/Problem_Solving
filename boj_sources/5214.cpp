#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> tube;
vector<vector<int>> v;
bool visp[100001];
bool vist[1001];
int n, m, k;
queue<pii> q;
int ans = -1;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> m;
    int a;
    v.resize(n+1);
    tube.resize(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a;
            tube[i].push_back(a);
            v[a].push_back(i);
        }
    }
    q.push({1, 1});
    visp[1] = true;
    while (!q.empty()) {
        pii a = q.front(); q.pop();
        int idx = a.first;
        int cnt = a.second;
        if (idx == n) {
            ans = cnt;
            break;
        }
        for (auto next : v[idx]) {
            if (vist[next])continue;
            vist[next] = true;
            for (auto k : tube[next]) {
                if (visp[k])continue;
                visp[k] = 1;
                q.push({ k, cnt + 1 });
            }
        }
    }
    cout << ans;
}
