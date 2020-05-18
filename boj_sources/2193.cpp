#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
using lint = long long;
lint n;
lint arr[91];
lint dp[91];
​
int main() {
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}
