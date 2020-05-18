#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int arr[4] = { 1, 5, 10, 50 };
int n;
int ans;
bool check[10000000];
void go(int idx, int sum, int cnt) {
    if (cnt == n) {
        if (!check[sum]) {
            check[sum] = true;
            ans++;
            return;
        }
        else return;
    }
​
    for (int i = idx; i < 4; i++) {
        go(i, sum + arr[i], cnt + 1);
    }
}
​
int main() {
    cin >> n;
    for (int i = 0; i < 4; i++) {
        go(0, arr[i], 1);
    }
    cout << ans;
}
