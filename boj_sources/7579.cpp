#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int d[10001];
int a[101]; int b[101]; int ans, sum;
int main() {
    int n, m;
    cin >> n>>m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i], sum += b[i];
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= b[i]; j--) {
            d[j] = max(d[j], d[j - b[i]] + a[i]);
        }
    }
    for (ans = 0; ans < sum && d[ans] < m; ans++);
    cout << ans;
}
