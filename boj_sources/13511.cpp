#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> pii;
long long par[100001][21];
long long d[100001];
long long dist[100001];
long long vis[100001];
vector<vector<pii>>v;
long long n;
long long op;
long long a, b, c, dd;
​
void dfs(long long here, long long depth, long long weight) {
    vis[here] = 1;
    dist[here] = weight;
    d[here] = depth;
    for (auto there : v[here]) {
        if (vis[there.first])continue;
        par[there.first][0] = here;
        dfs(there.first, depth + 1, weight + there.second);
    }
}
​
void f() {
    for (long long j = 1; j <= 20; j++) {
        for (long long i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}
​
long long lca(long long x, long long y) {
    if (d[x] > d[y]) swap(x, y);
    for (long long i = 20; i >= 0; i--) {
        if (d[y] - d[x] >= (1LL << i)) {
            y = par[y][i];
        }
    }
​
    if (x == y) return x;
​
    for (long long i = 20; i >= 0; i--) {
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
    cin >> n;
    v.resize(n + 1);
    for (long long i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }
    dfs(1, 1, 0);
    f();
    cin >> dd;
    while (dd--) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            long long aa = lca(a, b);
            cout << dist[a] + dist[b] - (2 * dist[aa])<<"\n";
        }
        else {
            cin >> a >> b >> c;
            long long aa = lca(a, b);
            long long diffx = d[a] - d[aa];
            if (diffx + 1 >= c) {
                c--;
                for (int i = 20; i >= 0; i--) {
                    if ((1LL << i) <= c) {
                        c -= (1LL << i);
                        a = par[a][i];
                    }
                }
                cout << a << "\n";
            }
            else {
                c = d[b] - d[aa] + 1 + diffx - c;
                for (int i = 20; i >= 0; i--) {
                    if ((1LL<< i) <= c) {
                        c -= (1LL << i);
                        b = par[b][i];
                    }
                }
                cout << b << "\n";
            }
​
        }
    }
    
}
