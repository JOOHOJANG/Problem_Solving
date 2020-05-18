#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <iostream>
​
int arr[100][100];
int visited[100][100];
int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int m, n, k;
​
int dfs(int x, int y) {
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx<0 || yy<0 || xx>=n || yy>=m) continue;
        if (!arr[xx][yy] && !visited[xx][yy]) {
            visited[xx][yy]++;
            cnt+=dfs(xx, yy);
        }
    }
    return cnt;
}
​
int main() {
    std::vector<int> size;
    int lx, ly, hx, hy;
​
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d %d", &lx, &ly, &hx, &hy);
        for (int j = lx; j < hx; j++) {
            for (int z = ly; z < hy; z++)
                arr[j][z]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arr[i][j] && !visited[i][j]) {
                int dd = dfs(i, j);
                size.push_back(dd);
            }
        }
    }
    std::cout << size.size() << "\n";
    std::sort(size.begin(), size.end());
    for (int i = 0; i < size.size(); i++) {
        if (size[i] != 1) size[i]--;
    }
    for (int i = 0; i < size.size(); i++)
        std::cout << size[i] << " ";
}
