#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 10000000
using namespace std;
int n, m;
int cnt;
int arr[501][501];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(arr, -1, sizeof(arr));
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        arr[x][y] = 1;   
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (arr[j][i] != -1 && arr[i][k] != -1) {
                    arr[j][k] = 1;
                }
            }
        }
    }
​
    for (int i = 1; i <= n; i++) {
        int lcnt = 0;
        for (int j = 1; j <= n; j++) {
            if (arr[j][i] == 1) lcnt++;
            if (arr[i][j] == 1)lcnt++;
        }
        if (lcnt == n-1) cnt++;
    }
    cout << cnt;
}
