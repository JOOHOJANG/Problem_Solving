#include <iostream>
#include <cstring>
using namespace std;
​
int arr[301][301];
int vis[301][301];
bool visited[301][301];
int pcnt, ycnt, n, m, flag;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
​
void dfs(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
        if (!arr[yy][xx]) vis[y][x]++;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
        if (arr[yy][xx] && !visited[yy][xx]) dfs(yy, xx);
    }
}
​
void decayy() {
    for (int i = 0; i<n; i++)
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) arr[i][j] -= vis[i][j];
            if (arr[i][j] < 0) arr[i][j] = 0;
        }
    memset(visited, false, sizeof(visited));
    memset(vis, 0, sizeof(vis));
}
​
void check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] && !visited[i][j]) dfs(i, j), pcnt++, flag = 1;
        }
    }
    decayy();
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    while (1) {
        pcnt = 0;
        flag = 0;
        check();
        if (pcnt >= 2) break;
        if (!flag) break;
        ycnt++;
    }
    if (pcnt >= 2) cout << ycnt;
    else cout << 0;
}
