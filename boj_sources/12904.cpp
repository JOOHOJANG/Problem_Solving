#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string a, b;
int main() {
    cin >> a >> b;
    while (1) {
        if (a.length() == b.length()) {
            if (a == b) {
                cout << 1;
            }
            else cout << 0;
            return 0;
        }
        if (b[b.length() - 1] == 'A') {
            b.pop_back();
        }
        else if (b[b.length() - 1] == 'B') {
            b.pop_back();
            reverse(b.begin(), b.end());
        }
    }
​
}
