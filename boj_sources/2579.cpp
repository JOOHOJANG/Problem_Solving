#include <iostream>
#include <algorithm>
using namespace std;
​
int dp[301];
int arr[301];
int n;
​
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
​
    dp[1] = arr[1];
    
    if(n>=2) dp[2] = dp[1] + arr[2];
​
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 3] + arr[i] + arr[i - 1], dp[i - 2] + arr[i]);
    }
    cout << dp[n];
}
