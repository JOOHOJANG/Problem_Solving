#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, w, n, x, y;
        cin >> h;
        cin >> w;
        cin >> n;
​
        x = n % h;
        y = n / h + 1;
​
        if (x == 0) {
            x = h;
        }
        if (!(n % h)) {
            y -= 1;
        }
​
        cout << x * 100 + y <<"\n";
    }
}
