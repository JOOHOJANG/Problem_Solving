#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min(a, min(b, min(abs(a - c), abs(b - d))));
}
