#include <stdio.h>
int arr[10];
int main() {
    int n, k, i;
    scanf("%d %d", &n, &k);
    int cnt = 0;
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (i = n - 1; i >= 0; i--) {
        if (arr[i] > k) continue;
        while (1) {
            k -= arr[i];
            cnt++;
            if (k < arr[i]) break;
        }
        if (k == 0) break;
    }
    printf("%d", cnt);
}
