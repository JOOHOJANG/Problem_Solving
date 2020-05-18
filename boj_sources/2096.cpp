#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[100001][3];
int ma, mi=100000000;
​
char arr2[100001][3];
int mymax(int a, int b) {
    if (a > b) return a;
    else return b;
}
int mymax2(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    else if (b >= a && b >= c) return b;
    else if (c >= a && c >= b) return c;
}
int mymin(int a, int b) {
    if (a < b) return a;
    else return b;
}
int mymin2(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    if (c <= a && c <= b) return c;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            arr2[i][j] = arr[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                arr[i][j] += mymax(arr[i - 1][j], arr[i - 1][j + 1]);
            }
            if (j == 1) {
                arr[i][j] += mymax2(arr[i - 1][j - 1], arr[i - 1][j], arr[i - 1][j + 1]);
            }
            if (j == 2) {
                arr[i][j] += mymax(arr[i - 1][j - 1], arr[i - 1][j]);
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (arr[n - 1][i] > ma) ma = arr[n - 1][i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = arr2[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                arr[i][j] += mymin(arr[i - 1][j], arr[i - 1][j + 1]);
            }
            if (j == 1) {
                arr[i][j] += mymin2(arr[i - 1][j - 1], arr[i - 1][j], arr[i - 1][j + 1]);
            }
            if (j == 2) {
                arr[i][j] += mymin(arr[i - 1][j - 1], arr[i - 1][j]);
            }
        }
    }
​
​
    for (int i = 0; i < 3; i++) {
        if (arr[n - 1][i] < mi) mi = arr[n - 1][i];
    }
    cout << ma << " " << mi;
}
