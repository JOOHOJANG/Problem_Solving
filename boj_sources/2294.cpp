#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int dp[10001];
int n, k;
​
int main() {
    cin >> n >> k;
    v.resize(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= k; i++)dp[i] = 100000;
    for (int i = 1; i <=n; i++) {
        for (int j = v[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - v[i]]+1);
        }
    }
    if (dp[k] == 100000)cout << -1;
    else cout << dp[k];
}
