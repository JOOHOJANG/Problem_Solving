#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, s, l;
int arr[101];
int dp[101][1001];
int go(int volume, int idx) {
    if (volume<0 || volume>l) return -100;
    if (idx == n) return volume;
    int& result = dp[idx][volume];
    if (result != -1) return result;
    return result = max(go(volume + arr[idx], idx + 1), go(volume - arr[idx], idx + 1));
    
}
int main() {
    cin >> n >> s >> l;
    for (int i = 0; i < n; i++)cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    int res = go(s, 0);
    if (res == -100) cout << -1;
    else cout << res;
}
