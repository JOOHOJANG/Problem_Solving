#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
​
int n;
int d[200001];
int par[200001][21];
​
​
void f() {
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}
​
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int>v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        par[i][0] = v[i];
    }
    f();
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        while (a) {
            for (int i = 20; i >= 0; i--) {
                if (a >=(1 << i)) {
                    b = par[b][i];
                    a -= (1 << i);
                }
            }
        }
        cout << b << "\n";
    }
}
