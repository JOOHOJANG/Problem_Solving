#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int arr[1025][1025];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x1, x2, y1, y2;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++) {
        cin >> arr[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            arr[i][j] += arr[i][j - 1];
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for (int j = x1; j <= x2; j++) {
            sum += (arr[j][y2] - arr[j][y1 - 1]);
        }
        cout << sum << "\n";
    }
​
}
