#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<int, ppi> ppp;
int arr[1001][1001];
int vis[1001][1001];
​
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
​
int n, m, h;
queue<ppi> q;
int ans = 0;
​
bool finflag;
void solve() {
​
    while (!q.empty()) {
        int cnt = q.front().first;
​
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
​
​
        for (int i = 0; i < 4; i++) {
            int xx = x + di[i];
            int yy = y + dj[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy] || arr[xx][yy] == -1 || arr[xx][yy] == 1) continue;
            if (arr[xx][yy] == 0) {
                q.push({ cnt + 1, {xx, yy} });
                vis[xx][yy] = 1;
                arr[xx][yy] = 1;
                ans = max(ans, cnt + 1);
            }
        }
​
    }
​
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            if (arr[j][k] == 0) {
                finflag = true;
            }
        }
    }
​
​
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({ 0, {i, j}});
                vis[i][j] = 1;
            }
        }
    }
​
​
    solve();
    if (finflag) {
        cout << -1;
​
    }
    else cout << ans;
}
