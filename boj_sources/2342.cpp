#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[5][5][100001];
vector<int > v;
int n;
​
int check(int from, int to) {
    if (from == 0) return 2;
    if (from == to) return 1;
    if (abs(from - to) == 2) return 4;
    return 3;
}
​
int solve(int x, int y, int target) {
    if (target == n) return 0;
    if (dp[x][y][target] !=-1) return dp[x][y][target];
​
    int right = solve(x, v[target], target + 1) + check(y, v[target]);
    int left = solve(v[target] , y, target + 1) + check(x,v[target]);
    return dp[x][y][target] = min(left, right);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a;
    while (1) {
        cin >> a;
        if (!a) break;
        v.push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    n = v.size();
    cout << solve(0, 0, 0);
}
