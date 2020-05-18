#include <stdio.h>
​
long long int gcd(long long int n,long long int m) {
    if (m == 0) return n;
    return gcd(m, n%m);
}
​
int main() {
    long long int m, n;
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < gcd(n, m); i++) {
        printf("1");
    }
}
