#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100000000
using namespace std;
int arr[17][17];
int n;
int dp[17][70000];
​
int solve(int cur, int vis) {
    if (vis == (1 << n) - 1) {
        return arr[cur][0] ? arr[cur][0] : MAX;
    }
    
    int& ret = dp[cur][vis];
    if (ret != -1) return ret;
    ret = MAX;
    for (int i = 0; i <= n; i++) {
        if (vis & (1 << i)) continue;
        if (arr[cur][i] == 0) continue;
        ret = min(ret, solve(i, vis | (1 << i)) + arr[cur][i]);
    }
    return ret;
}
​
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, 1);
    
}
