#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
using ll = long long;
​
int n;
int mmin = 21000000;
void go(int value, int cnt) {
    if (cnt > mmin) return;
    if (value == 1) {
        if (cnt < mmin) mmin = cnt;
        return;
    }
    if (value % 3 == 0) go(value / 3, cnt + 1);
    if (value % 2 == 0) go(value / 2, cnt + 1);
    go(value - 1, cnt + 1);
​
}
​
​
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
​
    cin >> n;
    go( n, 0);
    cout << mmin;
}
