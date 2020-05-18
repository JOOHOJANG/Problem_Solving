#include <cstdio>
#include <algorithm>
#include <iostream>
int arr[1000000];
int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    std::sort(arr, arr + n);
    for (i = 0; i < n; i++) printf("%d\n", arr[i]);
}
