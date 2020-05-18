#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
​
int n, m;
int arr[100][100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0 , 1 };
queue<pair<int, int>>que;
pair<int, int>curr;
​
void bfs() {
    que.push(make_pair(0, 0));
    int nx, ny;
    
    while (!que.empty()) {
        curr = que.front();
        que.pop();
​
        for (int i = 0; i < 4; i++) {
            nx = curr.first + dx[i];
            ny = curr.second + dy[i];
            if (nx<0 || ny<0 || nx>=m || ny>=n || arr[nx][ny] !=1) continue;
            que.push(make_pair(nx, ny));
            arr[nx][ny] = arr[curr.first][curr.second] + 1;
        }
    }
}
​
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf("%1d", &arr[i][j]);
    bfs();
    printf("%d", arr[m - 1][n - 1]);
}
