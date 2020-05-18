#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int d[501][2];
int dp[501][501];
int tmp;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i][0] >> d[i][1];
    double MA = pow(2, 31) - 1;
    int MAX = MA;
    
    
    for (int len = 1; len < n; len++) {
        for (int i = 1; i <= n-len; i++) {
            int j = i + len;
            if (i == j) continue;
            dp[i][j] = MAX;
            for (int k = i; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] +(d[i][0] * d[k][1] * d[j][1]));
            }
        }
    }
    cout << dp[1][n];
}
