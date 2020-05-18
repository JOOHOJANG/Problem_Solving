#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int dp[1001][1001];
int min(int a, int b) {
    if (a > b) return b;
    else return a;
}
int main() {
    cin >> n>>m;
    char a;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a;
            if (a - '0' == 1) dp[i][j] = 1;
        }
    }
​
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if(dp[i][j]){
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] > ans) ans = dp[i][j];
        }
    }
    cout << ans * ans;
}
