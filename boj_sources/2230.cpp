#include <iostream>
#include <algorithm>
using namespace std;
int n, m, ans = 2100000000;
int arr[100001];
​
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int s = 0, e = 1;
    while (s < n) {
        if (arr[e] - arr[s] < m) {
            e++;
            continue;
        }
        if (arr[e] - arr[s] == m) {
            ans = m;
            break;
        }
        ans = min(ans, arr[e] - arr[s]);
        s++;
    }
    cout << ans;
}
