#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int arr[51][51];
int tmp[51][51];
vector<pii> sanit;
int n, m, t;
int sx1, sx2, sy1, sy2;
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
​
void copy(int op) {
    if (op == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = arr[i][j];
            }
        }
    }
    else {
        for(int i =0 ; i<n; i ++)
            for (int j = 0; j < m; j++) {
                arr[i][j] = tmp[i][j];
            }
    }
}
​
void move() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0 || arr[i][j] == -1)continue;
            int x = i;
            int y = j;
            int val = arr[i][j];
            int vv = val / 5;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int xx = x + di[k];
                int yy = y + dj[k];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || arr[xx][yy] ==-1)continue;
                tmp[xx][yy] += vv;
                cnt++;
            }
            arr[x][y] -= (vv * cnt);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] += tmp[i][j];
        }
    }
    memset(tmp, 0, sizeof(tmp));
}
​
void clean() {
    for (int i = sx1 - 1; i >0; i--) arr[i][0] = arr[i - 1][0];
    for (int i = 0; i < m-1; i++) arr[0][i] = arr[0][i + 1];
    for (int i = 1; i <= sx1; i++)  arr[i-1][m-1] = arr[i][m-1];
    for (int i = m - 1; i > 1; i--) arr[sx1][i] = arr[sx1][i - 1];
    arr[sx1][1] = 0;
​
    for (int i = sx2 + 1; i < n - 1; i++) arr[i][0] = arr[i + 1][0];
    for (int i = 0; i < m - 1; i++) arr[n - 1][i] = arr[n - 1][i + 1];
    for (int i = n - 1; i >= sx2; i--)arr[i][m - 1] = arr[i - 1][m - 1];
    for (int i = m - 1; i > 1; i--) arr[sx2][i] = arr[sx2][i - 1];
    arr[sx2][1] = 0;
​
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1)sanit.push_back({ i, j });
        }
    }
    sx1 = sanit[0].first; sy1 = sanit[0].second;
    sx2 = sanit[1].first; sy2 = sanit[1].second;
​
    for (int j = 0; j < t; j++) {
        move();
        clean();
    }
    int cc = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0 && arr[i][j] != -1) cc += arr[i][j];
        }
    }
    cout << cc;
​
}
