#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> v;
queue<int> q;
int indeg[1001];
int last[1001];
int n, m;
int a, b;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (!m) {
        for (int i = 1; i <= n; i++) cout << i << " ";
        return 0;
    }
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        indeg[b] ++;
    }
​
    for (int i = 1; i <= n; i++) if (!indeg[i]) { 
        q.push(i);
        last[i] = 1;
    }
    while (!q.empty()) {
        int a = q.front(); q.pop();
        for (auto k : v[a]) {
            if (--indeg[k] == 0) {
                last[k] = (last[a] + 1);
                q.push(k);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << last[i] << " ";
}
