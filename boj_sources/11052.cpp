#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int dp[10001];
int n;
vector<int> v;
int main() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + v[j]);
        }
    }
    cout << dp[n];
}
