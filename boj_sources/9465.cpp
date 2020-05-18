#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
​
int t;
int n;
int dp[2][100001];
int arr[2][100001];
​
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
​
    cin >> t;
    while (t--) {
        cin >> n;
        arr[0][0] = arr[1][0] = dp[0][0] = dp[1][0] = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> arr[i][j];
            }
        }
        dp[0][1] = arr[0][1]; dp[1][1] = arr[1][1];
        for (int i = 2; i <= n; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
        }
        cout << max(dp[0][n], dp[1][n])<<"\n";
        memset(dp, 0, sizeof(dp)); memset(arr, 0, sizeof(arr));
    }
}
