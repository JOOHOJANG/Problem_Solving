#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int main() {
    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (!a && !b && !c) break;
        int aa = max(a, max(b, c));
        if ((2 * aa * aa == (a * a) + (b * b) + (c * c)))cout << "right\n";
        else cout << "wrong\n";
    }
}
