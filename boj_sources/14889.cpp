#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
​
int arr[21][21];
vector<int> vis, v;
int n;
int ans=123123123;
void go(int cnt, int idx) {
    if (v.size() == n / 2) {
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                ans1 += arr[v[i]][v[j]];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (vis[i] || vis[j]) continue;
                ans2 += arr[i][j];
            }
        }
        ans = min(ans, abs(ans1 - ans2));
        return;
    }
​
    for (int i = idx + 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            v.push_back(i);
            go(cnt + 1, i);
            v.pop_back();
            vis[i] = 0;
        }
    }
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
​
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            v.push_back(i);
            go(1, i);
            v.pop_back();
            vis[i] = 0;
        }
​
    }
    cout << ans;
}
