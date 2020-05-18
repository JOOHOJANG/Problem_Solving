#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<int, ppi> ppp;
int arr[101][101][101];
int vis[101][101][101];
​
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
int dh[2] = { 1, -1 };
int n, m, h;
queue<ppp> q;
int ans = 0;
​
bool finflag;
void solve() {
    
    while (!q.empty()) {
        int cnt = q.front().first;
        int hei = q.front().second.first;
        int x = q.front().second.second.first;
        int y = q.front().second.second.second;
        q.pop();
        for (int i = 0; i < 2; i++) {
            int hh = hei + dh[i];
            if (hh < 0 || hh >= h || vis[hh][x][y] || arr[hh][x][y] == -1 || arr[hh][x][y] ==1) continue;
            if (arr[hh][x][y] == 0) {
                q.push({ cnt + 1, {hh, {x, y}} });
                vis[hh][x][y] = 1;
                arr[hh][x][y] = 1;
                ans = max(ans, cnt + 1);
            }
        }
​
        for (int i = 0; i < 4; i++) {
            int xx = x + di[i];
            int yy = y + dj[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[hei][xx][yy] || arr[hei][xx][yy] == -1 || arr[hei][xx][yy] == 1) continue;
            if (arr[hei][xx][yy] == 0) {
                q.push({ cnt + 1, {hei, {xx, yy}} });
                vis[hei][xx][yy] = 1;
                arr[hei][xx][yy] = 1;
                ans = max(ans, cnt + 1);
            }
        }
​
    }
​
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (arr[i][j][k] == 0) {
                    finflag = true;
                }
            }
        }
    }
​
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> h;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[k][i][j];
                if (arr[k][i][j] == 1) {
                    q.push({ 0, {k, {i, j}} });
                    vis[k][i][j] = 1;
                }
            }
        }
    }
​
    solve();
    if (finflag) {
        cout << -1;
​
    }
    else cout << ans;
}
