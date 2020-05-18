#include <cstdio>
#include <algorithm>
#include <iostream>
int arr[10001];
int main() {
    int n, i, k,j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        arr[k]++;
    }
    for (i = 1; i <= 10000; i++) {
        if (arr[i] == 0) continue;
        for (j = 0; j < arr[i]; j++) printf("%d\n", i);
    }
}
