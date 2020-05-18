#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][100001];
int n, k;
int w[101];
int p[101];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (w[i] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + p[i]);
            }
        }
    }
    cout << dp[n][k];
}
