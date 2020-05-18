#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
​
int par[100001][21];
int n, m;
int d[100001];
bool vis[100001];
vector<vector<int>> v;
​
void dfs(int cur, int depth) {
    vis[cur] = true;
    d[cur] = depth;
    for (auto k : v[cur]) {
        if (!vis[k]) {
            dfs(k, depth + 1);
            par[k][0] = cur;
        }
    }
​
}
​
void f() {
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}
​
int lca(int x, int y) {
    if (d[x] > d[y]) swap(x, y);
​
    for (int j = 20; j >= 0; j--) {
        if (d[y] - d[x] >= (1 << j)) {
            y = par[y][j];
        }
    }
​
    if (x == y) return x;
​
    for (int j = 20; j >= 0; j--) {
        if (par[x][j] != par[y][j]) {
            x = par[x][j];
            y = par[y][j];
        }
    }
​
    return par[x][0];
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int a, b, c;
    v.resize(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> m;
    dfs(1, 0);
    f();
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        int aa = lca(a, b);
        int bb = lca(b, c);
        aa = d[aa] > d[bb] ? aa : bb;
        bb = lca(a, c);
        aa = d[aa] > d[bb] ? aa : bb;
        cout << aa << "\n";
    }
​
}
