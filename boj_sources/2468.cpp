#include <vector>
#include <iostream>
#include <cstring>
int area[101][101];
int visited[101][101];
int n, k, cnt, areamax, min= 101 ,max = 0;
int dx[4] = { 1,0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
​
void dfs(int x, int y, int h) {
    visited[y][x] = 1;
​
    for (int k = 0; k < 4; k++) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
        if (area[yy][xx] >= h && !visited[yy][xx]) {
            dfs(xx, yy, h);
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 0 ; i<n ; i++)
        for (int j = 0; j < n; j++) {   
            scanf("%d", &k);
            if (k >= max) max = k;
            if (k <= min) min = k;
            area[i][j] = k;
        }
    for (int h = min; h <= max; h++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[j][i] && area[j][i] >= h) {
                    dfs(i, j, h);
                    cnt++;
                }
            }
        }
        if (areamax < cnt) areamax = cnt;
        memset(visited, 0, sizeof(visited)), cnt = 0;
    }
    printf("%d", areamax);
}
