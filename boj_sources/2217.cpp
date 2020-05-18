#include <cstdio>
#include <algorithm>
#include <iostream>
int arr[100000];
int main() {
    int i, n, max = 0, cnt = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    std::sort(arr, arr + n);
    for (i = n - 1; i >= 0; i--) {
        int k = arr[i] * cnt;
        if (k > max) max = k;
        cnt++;
    }
    printf("%d", max);
}
