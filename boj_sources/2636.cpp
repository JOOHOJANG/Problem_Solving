#include <iostream>
#include <cstring>
using namespace std;
​
int arr[101][101];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int bcnt, rcnt, savecnt;
int visited[101][101];
​
void span(int x, int y) {
    arr[x][y] = 2;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if (!arr[xx][yy]) span(xx, yy);
    }
}
void bfs(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if (arr[xx][yy] == 2 && !visited[xx][yy]) bfs(xx, yy);
        else  if (arr[xx][yy] == 1) arr[xx][yy] = 2, visited[xx][yy] = 1;
        else if (!arr[xx][yy]) arr[xx][yy] = 2, visited[xx][yy] = 1, bfs(xx, yy);
    }
}
​
void set() {
    bfs(0, 0);
    memset(visited, 0, sizeof(visited));
    rcnt++;
}
void search() {
    savecnt = bcnt;
    bcnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (arr[i][j] == 1) bcnt++;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)  cin >> arr[i][j]; 
    span(0, 0);
    while (1) {
        search();
        if (bcnt == 0) break;
        set();
    }
    cout << rcnt << "\n" << savecnt;
}
