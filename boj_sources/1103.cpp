#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
​
int n, m;
int arr[51][51];
int vis[51][51];
int dp[51][51];
bool flag;
​
int dx[4] = { 0, 1 ,0, -1 };
int dy[4] = { 1, 0, -1, 0 };
​
int go(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == 10) return 0;
    
    if (vis[x][y]) {
        cout << -1;
        exit(0);
    }
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i] * arr[x][y];
        int yy = y + dy[i] * arr[x][y];
        ret = max(go(xx, yy) + 1, ret);
    }
    vis[x][y] = 0;
    return ret;
}
​
int main() {
​
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    char x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (x != 'H') arr[i][j] = x - '0';
            else arr[i][j] = 10;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0);
}
