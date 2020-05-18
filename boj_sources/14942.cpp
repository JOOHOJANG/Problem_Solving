#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v[100001];
int par[100001][21];
int dst[100001];
int d[100001];
int pw[100001];
int vis[100001];
int n;
void dfs(int here, int weight, int depth) {
    vis[here] = 1;
    d[here] = depth;
    dst[here] = weight;
    for (auto there : v[here]) {
        if (vis[there.first])continue;
        par[there.first][0] = here;
        dfs(there.first, weight + there.second, depth + 1);
    }
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
int lca(int x, int w) {
    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != 0 && w >= (dst[x] - dst[par[x][i]])) {
            w -= (dst[x]-dst[par[x][i]]);
            x = par[x][i];
        }
    }
    return x;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> pw[i];
    for (int i = 1; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        v[x].push_back({ y,z });
        v[y].push_back({ x,z });
    }
    dfs(1, 0, 0);
    f();
    for (int i = 1; i <= n; i++) {
        cout << lca(i, pw[i]) << "\n";
    }
    return 0;
}
​
