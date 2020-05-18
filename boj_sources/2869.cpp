#include <stdio.h>
​
int main() {
    int a, b, v;
    int cnt;
    scanf("%d %d %d", &a, &b, &v);
​
    cnt = (v - b - 1) / (a - b) + 1;
​
    printf("%d", cnt);
}
