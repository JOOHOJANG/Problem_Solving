#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 2100000000
using namespace std;
​
int dp[201][201];
vector<int> arr;
int solve(int st, int fi) {
    if (st == fi) return 0;
    if (dp[st][fi] != -1) return dp[st][fi];
    dp[st][fi] = MAX;
    
    for (int i = st; i < fi; i++) {
        int tmp = arr[st] != arr[i + 1] ? 1 : 0;
        dp[st][fi] = min(dp[st][fi], solve(st, i) + solve(i + 1, fi) + tmp);
    }
    return dp[st][fi];
}
​
int main() {
    int n, k;
    cin >> n >> k;
    arr.resize(n + 1);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)cin >> arr[i];
    cout << solve(1, n);
}
