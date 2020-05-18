#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
​
int indeg[32001];
vector<vector<int>> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)if (!indeg[i])q.push(i);
​
    while (!q.empty()) {
        int a = q.front(); q.pop();
        cout << a<<" ";
        for (auto k : v[a]) {
            if (--indeg[k] == 0)q.push(k);
        }
    }
}
