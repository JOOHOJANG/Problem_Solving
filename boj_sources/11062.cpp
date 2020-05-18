#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1001][1001][2];
int n;
int t;
vector<int> v;
​
int solve(int i, int j, int flag) {
    int& ret = dp[i][j][flag];
    if (ret != -1) return ret;
    if (i >= j) {
        if (!flag) {
            return v[i];
        }
        else return 0;
    }
​
    if (!flag) {
        ret = max(solve(i + 1, j, !flag) + v[i], solve(i, j - 1, !flag) + v[j]);
    }
    else {
        ret = min(solve(i + 1, j, !flag), solve(i, j - 1, !flag));
    }
    return ret;
}
​
void set() {
    v.clear();
    memset(dp, -1, sizeof(dp));
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i];
    cout << solve(1, n, 0) << "\n";
}
​
​
int main() {
    cin >> t;
    while (t--) set();
}
