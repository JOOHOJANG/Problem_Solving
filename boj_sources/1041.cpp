#include <iostream>
#include <algorithm>
#include <cstdio>
long long int min(long long int a, long long int b) {
    if (a < b) return a;
    else return b;
}
using namespace std;
int main() {
    long long int a[6], i, a1, a2, a3, n;
    long long int m1, m2, m3, sum=0;
    scanf("%lld", &n);
    for (i = 0; i < 6; i++) scanf("%lld", &a[i]);
    if (n == 1) {
        sort(a, a + 6);
        for (i = 0; i < 5; i++) sum += a[i];
        printf("%lld", sum);
    }
    else {
        a[0] = min(a[0], a[5]);
        a[1] = min(a[1], a[4]);
        a[2] = min(a[2], a[3]);
        sort(a, a + 3);
        a3 = a[0] + a[1] + a[2];
        a2 = a[0] + a[1];
        a1 = a[0];
        m1 = 4 * (n - 1)*(n - 2) + (n - 2)*(n - 2);
        m2 = 4 * ((2 * n) - 3);
        m3 = 4;
        sum += (a1 * m1) + (a2*m2) + (a3*m3);
        printf("%lld", sum);
    }
}
