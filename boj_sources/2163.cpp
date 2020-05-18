#include <iostream>
using namespace std;
​
int n, m, c1, c2;
int nn;
int ans;
int main() {
    cin >> n >> m;
    nn = n;
    while (n > 1)c1++, n--;
    while (m > 1) c2++, m--;
    ans = c1 + nn * c2;
    cout << ans;
}
