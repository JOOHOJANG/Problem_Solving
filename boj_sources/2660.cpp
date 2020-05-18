#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
​
int n, x, y, cnt;
int arr[51][51];
int ar[51];
int m = 999999999;
​
int main() {
    memset(arr, 10000, sizeof(arr));
    cin >> n;
    while (1) {
        cin >> x >> y;
        if (x == -1 && y == -1) break;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (arr[j][k] > arr[j][i] + arr[i][k]) arr[j][k] = arr[j][i] + arr[i][k];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            ar[i] = max(ar[i], arr[i][j]);
        }
        m = min(ar[i], m);
    }
    for (int i = 1; i <= n; i++) if (m == ar[i]) cnt++;
    cout << m << " " << cnt << "\n";
    for (int i = 1; i <= n; i++) if (m == ar[i]) cout << i << " ";
}
