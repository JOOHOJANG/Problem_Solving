#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int w, h;
int arr[51][51];
int vis[51][51];
int di[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dj[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
​
void dfs(int x, int y) {
    vis[x][y] = 1;
​
    for (int i = 0; i < 8; i++) {
        int xx = x + di[i];
        int yy = y + dj[i];
        if (xx < 0 || xx >= w || yy < 0 || yy >= h) continue;
        if (!vis[xx][yy] && arr[xx][yy]) dfs(xx, yy);
    }
}
int main() {
    while (1) {
        cin >> w >> h;
        swap(w, h);
        if (!w) break;
        int cnt = 0;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                cin >> arr[i][j];
            }
        }
​
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (arr[i][j] && !vis[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        memset(arr, 0, sizeof(arr));
        memset(vis, false, sizeof(vis));
    }
}
