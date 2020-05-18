#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
​
int arr[301][301];
​
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i][j - 1];
        }
    }
    cin >> k;
    int x1, x2, y1, y2;
    while (k--) {
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++) {
            sum += (arr[i][y2] - arr[i][y1 - 1]);
        }
        cout << sum << "\n";
    }
}
