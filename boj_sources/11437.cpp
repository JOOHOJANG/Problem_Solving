#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>v;
int vis[50001];
int d[50001];
int par[50001][20];
int n; int m;
void dfs(int here, int depth) {
    vis[here] = 1;
    d[here] = depth;
    for (int there : v[here]) {
        if (vis[there])continue;
        par[there][0] = here;
        dfs(there, depth + 1);
    }
}
void f() {
    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}
​
int lca(int x, int y) {
    if (d[x] > d[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i)) {
            y = par[y][i];
        }
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    f();
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}
