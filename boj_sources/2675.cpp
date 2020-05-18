#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
​
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; string str;
        cin >> n >> str;
        for (int i = 0; i < str.size(); i++) {
            for (int j = 0; j < n; j++) {
                cout << str[i];
            }
        }
        cout << "\n";
    }
}
