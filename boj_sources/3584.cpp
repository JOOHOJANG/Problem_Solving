#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
​
int d[200001];
int par[200001][21];
vector<vector<int>> v;
int indeg[200001];
int vis[200001];
int n, m, a, b, c, t;
int root;
​
void sett() {
    memset(d, 0, sizeof(d));
    memset(par, 0, sizeof(par));
    v.clear(); v.resize(0);
    memset(indeg, 0, sizeof(indeg));
    memset(vis, 0, sizeof(vis));
    root = 0;
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
void dfs(int here, int depth) {
    vis[here] = 1;
    d[here] = depth;
    for (auto there : v[here]) {
        if (vis[there])continue;
        par[there][0] = here;
        dfs(there, depth + 1);
    }
}
​
int lca(int x, int y) {
    if (d[x] > d[y]) swap(x, y);
​
    for (int i = 20; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i)) {
            y = par[y][i];
        }
    }
​
    if (x == y) return x;
​
    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
​
    return par[x][0];
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        v.resize(n + 1);
        for (int i = 0; i<n - 1; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            indeg[b]++;
        }
        for (int i = 1; i <= n; i++) {
            if (!indeg[i]) root = i;
        }
​
        dfs(root, 0);
        f();
        cin >> a >> b;
        cout << lca(a, b)<<"\n";
        sett();
    }
}
