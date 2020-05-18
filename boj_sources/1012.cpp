#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
​
int arr[50][50];
int visited[50][50];
int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int m, n, k;
int test;
​
void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx<0 || yy<0 || xx>=m || yy>=n) continue;
        if (arr[xx][yy] && !visited[xx][yy]) {
            visited[xx][yy]++;
            dfs(xx, yy);
        }
    }
}
​
int main() {
    int x, y;
    scanf("%d", &test);
    for (int z = 0; z < test; z++) {
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d %d", &x, &y);
            arr[x][y] = 1;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && arr[i][j]) {
                    ans++;
                    visited[i][j]++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
}
