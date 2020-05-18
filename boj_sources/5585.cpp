#include <stdio.h>
​
int main() {
    int coin[6] = { 500, 100, 50, 10, 5, 1 };
    int i = 0;
    int n;
    int cnt = 0;
    scanf("%d", &n);
    n = 1000 - n;
    while (n > 0) {
        if (n >= coin[i])
            n -= coin[i], cnt++;
        else
            i++;
    }
    printf("%d", cnt);
}
