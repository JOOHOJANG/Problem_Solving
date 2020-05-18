#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
​
int mmin = 2100000000, mmax = -2100000000;
int n;
vector<int>v, vv;
void solve(int p, int m, int d, int u, int cnt, int val) {
    if (cnt == n) {
        mmax = max(mmax, val);
        mmin = min(mmin, val);
        return;
    }
​
    if (p > 0) solve(p - 1, m, d, u, cnt + 1, val + v[cnt]);
    if (m > 0) solve(p, m - 1, d, u, cnt + 1, val - v[cnt]);
    if (d > 0) solve(p, m, d - 1, u, cnt + 1, val / v[cnt]);
    if (u > 0) solve(p, m, d, u - 1, cnt + 1, val * v[cnt]);
}
​
int main() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    solve(a, b, d, c, 1, v[0]);
    cout << mmax << "\n" << mmin;
}
