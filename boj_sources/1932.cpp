#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[501][501];
int n;
int main() {
    cin >> n;
    cin >> arr[1][0];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cin >> arr[i][j];
        }
        for (int j = 0; j < i; j++) {
            if (j == 0) { arr[i][j] += arr[i - 1][j]; continue; }
            if (j == i - 1) { arr[i][j] += arr[i - 1][j - 1]; continue; }
            arr[i][j] = max(arr[i][j] + arr[i - 1][j - 1], arr[i][j] + arr[i - 1][j]);
        }
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (arr[n][i] > m)m = arr[n][i];
    }
    cout << m;
}
