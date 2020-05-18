#include <stdio.h>
int arr[20000001];
​
int main() {
    int num = 10000000;
    int n, m, k, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        arr[k + num]++;
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &k);
        printf("%d ", arr[k + num]);
    }
}
