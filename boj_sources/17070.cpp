#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int>pii;
int vis[17][17];
int n;
int cnt;
​
int di[3] = { 0, 1, 1 };
int dj[3] = { 1, 1, 0 };
​
void go(pii a, pii b) {
    bool flag = false;
    if (b.first == n - 1 && b.second == n - 1) {
        cnt++;
        return;
    }
    if (a.first == b.first) {
        for (int i = 0; i < 3; i++) {
            int xx = b.first + di[i];
            int yy = b.second + dj[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= n) {
                flag = true;
                continue;
            }
            if (vis[xx][yy]) {
                flag = true;
                continue;
            }
            if (i == 0 && !vis[xx][yy]) {
                go(b, { xx, yy });
            }
        }
        if (!flag) {
            go(b, { b.first + 1, b.second + 1 });
        }
    }
    else if (a.second == b.second) {
        for (int i = 0; i < 3; i++) {
            int xx = b.first + di[i];
            int yy = b.second + dj[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= n) {
                flag = true;
                continue;
            }
            if (vis[xx][yy]) {
                flag = true;
                continue;
            }
            if (i ==2  && !vis[xx][yy]) {
                go(b, { xx, yy });
            }
        }
        if (!flag) {
            go(b, { b.first + 1, b.second + 1 });
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            int xx = b.first + di[i];
            int yy = b.second + dj[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= n) {
                flag = true;
                continue;
            }
            if (vis[xx][yy]) {
                flag = true;
                continue;
            }
            if (i == 2 && !vis[xx][yy]) {
                go(b, { xx, yy });
            }
            if (i == 0 && !vis[xx][yy]) {
                go(b, { xx, yy });
            }
        }
        if (!flag) {
            go(b, { b.first + 1, b.second + 1 });
        }
    }
}
​
int main() {
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a) {
                vis[i][j] = 1;
            }
        }
    }
    go({ 0, 0 }, { 0, 1 });
    cout << cnt;
​
}
