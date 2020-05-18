#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
​
int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    int ans = 0;
    for (int i= 0; i < n; i++) {
        ans += (str[i] - '0');
    }
    cout << ans;
}
