#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int arr[7][2];
int n, k;
int cnt;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    int x, y;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        arr[y][x]++;
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 2; j++) {
            cnt += arr[i][j] / k;
            if (arr[i][j] % k)cnt++;
        }
    }
    cout << cnt;
}
