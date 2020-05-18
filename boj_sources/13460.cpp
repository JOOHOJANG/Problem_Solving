#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, int> pii;
​
​
int ans = -1;
int arr[10][10];
int vis[11][11][11][11];
​
int dir[4][2] = { {1,0}, {0, 1}, {-1, 0}, {0, -1} };
int n, m;
int ex, ey;
int irx, iry, ibx, iby;
​
struct ball {
    int dep, rx, ry, bx, by;
};
​
void move(int& x, int& y, int d) {
    while (1) {
        x += dir[d][0]; y += dir[d][1];
        if (arr[x][y] == 1) {
            x -= dir[d][0]; y -= dir[d][1];
            break;
        }
        else if (arr[x][y] == 2) {
            break;
        }
    }
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == 'B') ibx = i, iby = j;
            if (str[j] == 'R') irx = i, iry = j;
            if (str[j] == 'O')ex = i, ey = j, arr[i][j] = 2;
            if (str[j] == '#') arr[i][j] = 1;
            if (str[j] == '.') arr[i][j] = 0;
        }
    }
    
    queue<ball> q;
    q.push({ 0, irx, iry, ibx, iby });
    vis[irx][iry][ibx][iby] = 1;
    while (!q.empty()) {
        ball cur = q.front(); q.pop();
​
        if (cur.dep > 10) {
            break;
        }
        if (cur.rx == ex && cur.ry == ey) {
            ans = cur.dep;
            break;
        }
        
​
        for (int i = 0; i < 4; i++) {
            int rx = cur.rx; int ry = cur.ry;
            int bx = cur.bx; int by = cur.by;
            move(rx, ry, i), move(bx, by, i);
            if (bx == ex && by == ey) continue;
            if (rx == bx && ry == by) {
                switch (i) {
                case 0:
                    cur.rx < cur.bx ? rx-- : bx--; break;
                case 2:
                    cur.rx < cur.bx ? bx++ : rx++; break;
                case 1:
                    cur.ry < cur.by ? ry-- : by--; break;
                case 3:
                    cur.ry < cur.by ? by++ : ry++; break;
                }
            }
            if (!vis[rx][ry][bx][by]) {
                vis[rx][ry][bx][by] = 1;
                q.push({ cur.dep + 1, rx, ry, bx, by });
            }
        }
    }
    cout << ans;
}
