#include <iostream>
#include <algorithm>
using namespace std;
​
int house[1001][3];
int dp[1001][3];
int n;
int ans= 210000000;
​
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++) cin >> house[i][j];
    dp[1][0] = house[1][0];
    dp[1][1] = house[1][1];
    dp[1][2] = house[1][2];
        for (int j = 2; j <= n; j++) {
            dp[j][0] = min(dp[j - 1][1] + house[j][0], dp[j - 1][2] + house[j][0]);
            dp[j][1] = min(dp[j - 1][0] + house[j][1], dp[j - 1][2] + house[j][1]);
            dp[j][2] = min(dp[j - 1][1] + house[j][2], dp[j - 1][0] + house[j][2]);
        }
    for (int i = 0; i < 3; i++) {
        if (dp[n][i] < ans) ans = dp[n][i];
    }
    cout << ans;
}
