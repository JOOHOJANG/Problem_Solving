#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long lint;
lint dp[101][21];
vector<int> v;
int main() {
    int n;
    cin >> n;
    v.resize(n+1);
    for (int i = 1; i <= n; i++)cin >> v[i];
    dp[1][v[1]]++;
    for (int i = 2; i < n; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i - 1][j]) {
                if (j + v[i] <= 20) dp[i][j + v[i]] += dp[i - 1][j];
                if (j - v[i] >= 0) dp[i][j - v[i]] += dp[i-1][j];
            }
        }
    }
    cout << dp[n-1][v[n]];
}
