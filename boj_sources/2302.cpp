#include <iostream>
using namespace std;
​
int arr[41];
int vip, x,n;
int ans = 1;
int cnt;
int fibo(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibo(n - 1) + fibo(n - 2);
}
​
int main() {
    cin >> n;
    cin >> vip;
    for (int i = 0; i < vip; i++) {
        cin >> x;
        arr[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!arr[i]) cnt++;
        else ans *= fibo(cnt + 1), cnt = 0;
        if (i == n) ans *= fibo(cnt + 1);
    }
    cout << ans;
}
