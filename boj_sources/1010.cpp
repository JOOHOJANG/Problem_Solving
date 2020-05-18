#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
​
long long dp[30][30];
long long fact(int a) {
    int ans = 1;
    int b = 1;
    for (int i = 1; i <= a; i++) {
        ans *= b;
        b++;
    }
    return ans;
}
int main() {
    long long n, k;
    int x;
    cin >> x;
    while (x--) {
        cin >> k >> n;
        if (k > 18) k = n - k;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == j || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        cout << dp[n][k] << "\n";
        memset(dp, 0, sizeof(dp));
    }
}
