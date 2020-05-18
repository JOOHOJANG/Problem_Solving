#include <cstdio>
#include <algorithm>
#include <iostream>
long long int arr[10000];
int main() {
    long long int n, i, j;
    long long int sum = 0;
    scanf("%lld", &n);
    for (i = 0; i < n; i++) scanf("%lld", &arr[i]);
    std::sort(arr, arr + n);
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++)
            sum += arr[j] - arr[i];
    }
    printf("%lld", 2 * sum);
}
