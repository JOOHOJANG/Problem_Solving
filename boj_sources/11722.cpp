#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
​
int arr[1002];
int dp[1002];
int n, cur, cnt; 
int mmax;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    memset(dp, 1, sizeof(dp));
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        mmax = 0;
        for (int j = i-1; j >= 1; j--) {
            if (arr[i] < arr[j]) {
                if (mmax < dp[j])mmax = dp[j];
            }
        }
        dp[i] = mmax + 1;
    }
    mmax = -1;
    for (int i = 1; i <= n; i++) {
        if (mmax < dp[i])mmax = dp[i];
    }
    cout << mmax;
}
