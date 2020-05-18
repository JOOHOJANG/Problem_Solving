#include <iostream>
using namespace std;
int fact(int n) {
    if (n == 1 || n == 0) return 1;
    int a = 1;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= a;
        a++;
    }
    return ans;
}
​
int main() {
    int n, k;
    cin >> n >> k;
    cout<<fact(n)/(fact(k)*fact(n-k));
​
}
