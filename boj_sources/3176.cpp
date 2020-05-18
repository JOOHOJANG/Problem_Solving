#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int d[200001];
int par[200001][21];
int mmin[200001][21];
int mmax[200001][21];
vector<vector<pii>> v;
int indeg[200001];
int vis[200001];
int n, m, a, b, c, t;
int root;
​
void f() {
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
            mmin[i][j] = min(mmin[i][j - 1], mmin[par[i][j - 1]][j - 1]);
            mmax[i][j] = max(mmax[i][j - 1], mmax[par[i][j - 1]][j - 1]);
        }
    }
}
​
void dfs(int here, int depth) {
    vis[here] = 1;
    d[here] = depth;
    for (auto there : v[here]) {
        if (vis[there.first])continue;
        dfs(there.first, depth + 1);
        par[there.first][0] = here;
        mmin[there.first][0] = there.second;
        mmax[there.first][0] = there.second;
    }
}
​
pii lca(int x, int y) {
    int ma = -2100000000, mi = 2100000000;
    if (d[x] > d[y]) swap(x, y);
​
    for (int i = 20; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i)) {
            mi = min(mi, mmin[y][i]);
            ma = max(ma, mmax[y][i]);
            y = par[y][i];
        }
    }
​
    if (x == y) return { ma, mi };
​
    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            mi = min(mi, min(mmin[x][i], mmin[y][i]));
            ma = max(ma, max(mmax[x][i], mmax[y][i]));
            x = par[x][i];
            y = par[y][i];
        }
    }
    ma = max(ma, max(mmax[x][0], mmax[y][0]));
    mi = min(mi, min(mmin[x][0], mmin[y][0]));
    return { ma, mi };
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b>>c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }
    dfs(1, 0);
    f();
    cin >> c;
    while (c--) {
        cin >> a >> b;
        pii tmp = lca(a, b);
        cout << tmp.second << " " << tmp.first << "\n";
    }
}
