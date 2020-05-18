#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<int, ppi> ppp;
char arr[1001][1001];
int dist[1001][1001][2];
int ans = 102232313;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<ppp> q;
​
bool flag;
​
int n, m;
struct map {
    int x; int y; int w;
};
int bfs() {
    queue<map> q;
    q.push({ 0, 0, 0 });
    dist[0][0][0] = 1;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, w = q.front().w;
        q.pop();
        if (x == n - 1 && y == m - 1) return dist[x][y][w];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny][w]) continue;
            if (arr[nx][ny] == '0') {
                dist[nx][ny][w] = dist[x][y][w] + 1;
                q.push({ nx, ny, w });
            }
            if (arr[nx][ny] == '1' && w == 0) {
                dist[nx][ny][1] = dist[x][y][w] + 1;
                q.push({ nx, ny, 1 });
            }
        }
    }
    return -1;
}
​
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << bfs();
}
