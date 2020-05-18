#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int tmp = b;
    a *= d, b *= d;
    c *= tmp; d *= tmp;
    int k = gcd(a + c, b);
    int z = a + c;
    z /= k;
    b /= k;
    cout << z<<" " << b;
}
