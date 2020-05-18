#include <stdio.h>
​
int search(int girl, int boy) {
    if (girl < 2 || boy < 1) return -1;
    int cnt = 0;
    while (1) {
        if (girl == 1) break;
        girl -= 2;
        boy -= 1;
        cnt++;
        if (boy <= 0 || girl <= 0) break;
    }
    return cnt;
}
​
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int res = 0, max = 0;
    while (1) {
        int a = search(n - k, m - res);
        if (a > max) max = a;
        k--, res++;
        if (k < 0) break;
    }
    printf("%d", max);
}
