#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;
int n;
int arr[3001];
int cnt[1000001];
ll dp[3001][3001];
​
ll go(int st, int dt, bool flag) {
    ll foo = dp[st][dt];
    if (foo != -1) return foo;
    foo = 0;
    ll diff = arr[dt] - arr[st];
    if (arr[dt] + diff > 1000000 || cnt[arr[dt] + diff] == -1) {
        if (flag) return foo = arr[st] + arr[dt];
        else return foo;
    }
    else {
        int next = cnt[arr[dt] + diff];
        return foo = arr[st] + go(dt, next, 1);
    }
}
​
int main() {
    cin >> n;
    memset(cnt, -1, sizeof(cnt));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]] = i;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, go(i, j, 0));
        }
    }
    cout << ans;
}
