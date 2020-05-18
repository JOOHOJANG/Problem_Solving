#include <iostream>
#include <vector>
using namespace std;
​
vector<vector<int>>v;
int n;
int m;
int cnt = -1;
int vis[101];
void solve(int idx) {
    cnt++;
    vis[idx] = 1;
    for (auto k : v[idx]) {
        if (!vis[k]) {
            solve(k);
        }
    }
}
int main() {
    cin >> n;
​
    v.resize(n + 1);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    solve(1);
    cout << cnt;
​
}
