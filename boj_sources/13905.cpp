#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int n, m;
vector<vector<pii>>v;
int st, fi;
​
bool bfs(int lim) {
    queue<int> q;
    q.push(st);
​
    vector<bool> vis(n + 1, false);
    vis[st] = true;
    while (!q.empty()) {
        int a = q.front(); q.pop();
        if (a == fi) return true;
        for (auto k : v[a]) {
            int val = k.first;
            int next = k.second;
            if (!vis[next] && val >= lim) {
                q.push(next);
                vis[next] = true;
            }
        }
    }
    return false;
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> st >> fi;
    v.resize(n + 1);
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ c, b });
        v[b].push_back({ c, a });
    }
​
    int hi = 1000000, lo = 0;
    while (hi >= lo) {
        int mid = (hi + lo) / 2;
        if (bfs(mid)) lo = mid+1;
        else hi = mid-1;
    }
​
    if (hi == -1) cout << 0;
    else cout << hi;
​
}
