#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
​
int n, m;
char arr[21][21];
bool vis[21][21];
pii a, b;
vector<pii>v;
int ans = 123123123;
​
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
void go(int cnt, pii a, pii b) {
    if (cnt > 10) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int x1 = a.first + di[i];
        int x2 = b.first + di[i];
        int yy1 = a.second + dj[i];
        int y2 = b.second + dj[i];
        if (vis[x1][yy1] && vis[x2][y2]) continue;
        if ((x1 < 0 || x1 >= n || yy1 < 0 || yy1 >= m) && (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)) continue;
        if ((x1 < 0 || x1 >= n || yy1 < 0 || yy1 >= m) || (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)) {
            ans = min(ans, cnt + 1);
            return;
        }
​
        if (vis[x1][yy1]) {
            x1 -= di[i];
            yy1 -= dj[i];
            if (x1 == x2 && yy1 == y2) continue;
            go(cnt + 1, { x1, yy1 }, { x2, y2 });
        }
        else if (vis[x2][y2]) {
            x2 -= di[i];
            y2 -= dj[i];
            if (x1 == x2 && yy1 == y2) continue;
            go(cnt + 1, { x1, yy1 }, { x2, y2 });
        }
        else {
            go(cnt + 1, { x1, yy1 }, { x2, y2 });
        }
    }
​
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'o') {
                v.push_back({ i, j });
            }
            else if (arr[i][j] == '#') vis[i][j] = true;
        }
    }
    
    go(0, v[0], v[1]);
    if (ans > 10) cout << -1;
    else cout << ans;
}
