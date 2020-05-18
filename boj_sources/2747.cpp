#include <stdio.h>
​
int fibo(int n) {
    int g, h, f, i;
    if (n > 1) {
        g = 0;
        h = 1;
        for (i = 2; i <= n; i++) {
            f = g + h;
            g = h;
            h = f;
        }
    }
    else f = n;
    return f;
}
int main() {
    int k;
    scanf("%d", &k);
    int a = fibo(k);
    printf("%d", a);
}
