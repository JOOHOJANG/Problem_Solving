#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
​
int dist[40001];
int par[100001][21];
int d[100001];
int vis[100001];
vector<vector<pii>>v;
int n, m;
​
void dfs(int cur, int weight, int depth) {
    vis[cur] = 1;
    dist[cur] = weight;
    d[cur] = depth;
    for (auto next : v[cur]) {
        if (vis[next.first])continue;
        par[next.first][0] = cur;
        dfs(next.first, weight + next.second, depth + 1);
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
    v.resize(n + 1);
    int a, b, c;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c, });
        v[b].push_back({ a,c });
    }
    cin >> m;
    dfs(1, 0, 0);
    f();
    while (m--) {
        cin >> a >> b;
        int aa = lca(a, b);
        cout << (dist[a] + dist[b] - (2 * dist[aa]))<<"\n";
    }
}
