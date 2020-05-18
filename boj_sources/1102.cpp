#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 1000000000
using namespace std;
int n;
int dp[17][65000];
int arr[17][17];
int p;
​
string str;
​
int solve(int level, int state) {
    if (level >= p) return 0;
    
    dp[level][state] = MAX;
    for (int i = 0; i < n; i++) {
        if (state & 1 << i) {
            for (int j = 0; j < n; j++) {
                if (!(state & 1 << j)) {
                    dp[level][state] = min(dp[level][state], solve(level + 1, state | (1 << j))+ arr[i + 1][j + 1]);
                }
            }
        }
    }
    return dp[level][state];
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cin >> str;
    cin >> p;
    int cur = 0, state = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'Y') {
            cur++;
            state = state | (1 << i);
        }
    }
    if (cur >= p) {
        cout << 0;
        return 0;
    }
    int ans = solve(cur, state);
    if (ans == MAX) cout << -1;
    else cout << ans;
}
