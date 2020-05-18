#include <iostream>
using namespace std;
using ll = long long;
​
ll n;
ll ans;
ll fibo[91];
int main() {
    cin >> n;
    if (n > 0) {
        fibo[1] = 1;
        for (ll i = 2; i <= n; i++) {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        ans = fibo[n];
    }
    cout << ans;
}
