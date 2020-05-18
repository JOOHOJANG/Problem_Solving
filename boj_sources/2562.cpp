#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
​
int main() {
    int ans = 0;
    int pos = 0;
    int a;
    for (int i = 1; i <= 9; i++) {
        cin >> a;
        if (a > ans) {
            ans = a;
            pos = i;
        }
    }
    cout << ans << "\n" << pos;
}
