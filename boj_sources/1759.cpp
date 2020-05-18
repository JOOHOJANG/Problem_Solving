#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
​
int l, c;
char a[16];
void go(int idx, int cnt, int ja, int mo, string s) {
    if (cnt == l) {
        if (ja >= 2 && mo >= 1) {
            cout << s << "\n";
            return;
        }
    }
    if (idx == c) return;
    if (a[idx] == 'a' || a[idx] == 'e' || a[idx] == 'i' || a[idx] == 'o' || a[idx] == 'u')
        go(idx + 1, cnt + 1, ja, mo + 1, s + a[idx]);
    else 
        go(idx + 1, cnt + 1, ja + 1, mo, s + a[idx]);
    go(idx + 1, cnt, ja, mo, s);
}
int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++)cin >> a[i];
    sort(a, a + c);
    go(0, 0, 0, 0, "");
}
