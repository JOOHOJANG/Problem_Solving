#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int arr[501][501];
int vis[501][501];
int n, m;
​
int di[4] = { 0, 1, 0, 1 };
int dj[4] = { 1, 0, -1, 0 };
​
int ans;
​
void tt(int x, int y) {
    if (x >= 1 && x <= n - 2 && y >= 0 && y <= m - 2) {
        int a = arr[x][y] + arr[x-1][y] + arr[x+1][y] + arr[x][y+1];
        ans = max(a, ans);
    }
    if (x >= 1 && x <= n - 2 && y >= 1 && y <= m - 1) {
        int a = arr[x][y] + arr[x - 1][y] + arr[x + 1][y] + arr[x][y - 1];
        ans = max(a, ans);
    }
    if (x >= 0 && x <= n - 2 && y >= 1 && y <= m - 2) {
        int a = arr[x][y] + arr[x][y-1] + arr[x][y+1] + arr[x+1][y];
        ans = max(a, ans);
    }
    if (x >= 1 && x <= n - 1 && y >= 1 && y <= m - 2) {
        int a = arr[x][y] + arr[x][y - 1] + arr[x][y + 1] + arr[x - 1][y];
        ans = max(a, ans);
    }
}
​
​
void dfs(int x, int y, int cnt, int val) {
    if (cnt == 4) {
        ans = max(ans, val);
        return;
    }
​
    for (int i = 0; i < 4; i++) {
        int xx = x + di[i];
        int yy = y + dj[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if (!vis[xx][yy]) {
            vis[xx][yy] = true;
            dfs(xx, yy, cnt + 1, val + arr[xx][yy]);
            vis[xx][yy] = false;
        }
    }
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
​
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                vis[i][j] = 1;
                dfs(i, j, 1, arr[i][j]);
                tt(i, j);
                vis[i][j] = 0;
            }
        }
    }
    cout << ans;
}
