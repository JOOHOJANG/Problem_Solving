#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
void bfs();
void wall(int cnt);
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
int ans;
int arr[9][9];
int tmp[9][9];
int n, m;
​
void wall(int cnt) {
    if (cnt == 3) {
        bfs();
        return;
    }
​
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == 0) {               
                tmp[i][j] = 1;
                wall(cnt + 1);
                tmp[i][j] = 0;
            }
        }
    }
}
​
void bfs() {
    int arrr[9][9];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arrr[i][j] = tmp[i][j];
        }
    }
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arrr[i][j] == 2) q.push({ i, j });
        }
    }
​
    while (!q.empty()) {
        int x = q.front().first; 
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + di[i];
            int yy = y + dj[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (arrr[xx][yy] == 0) {
                arrr[xx][yy] = 2;
                q.push({ xx, yy });
            }
        }
    }
​
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arrr[i][j] == 0) cnt++;
        }
    }
​
    ans = max(ans, cnt);
​
}
​
int main() {
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
​
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                for (int k = 0; k < n; k++) {
                    for (int t = 0; t < m; t++) {
                        tmp[k][t] = arr[k][t];
                    }
                }
​
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0;
            }
        }
    }
    cout << ans;
}
