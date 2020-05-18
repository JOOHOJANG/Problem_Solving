#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
​
int n, k;
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
​
    double val = 0;
    for (int i = 1; i <= n; i++) val += i;
    val /= n;
​
    for (int i = 2; i <= k; i++) {
        int a = val / 1;
        double tmp = val;
        tmp = (tmp * a) / n;
        double tmp2 = 0;
        for (int j = a + 1; j <= n; j++)tmp2 += j;
        tmp2 /= n;
        val = tmp + tmp2;
    }
    cout << fixed;
    cout.precision(10);
    cout << val;
}
