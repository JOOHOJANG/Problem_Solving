#include <iostream>
#include <vector>
using namespace std;
​
long long dp[1001][1001];
​
int main() {
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j || j == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
        }
    }
    cout << dp[n][k];
}
