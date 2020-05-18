#include <stdio.h>
#include <stdlib.h>
​
long long ssearch(long long arr[], long long n, long long key, long long r) {
    long long i;
    long long left = 0, right = 2 * r, mid = (left + right) / 2, res = 0;
    long long sum = 0;
    while (left <= right) {
        sum = 0;
        for (i = 0; i < n; i++) if (arr[i] - mid > 0) sum += arr[i] - mid;
        if (sum == key) return mid;
        else if (sum > key) left = mid + 1;
        else right = mid - 1;
        mid = (left + right) / 2;
    }
    return mid;
}
​
int main() {
    long long n, m, i;
    long long max = 0;
    scanf("%lld %lld", &n, &m);
    long long* arr = (long long*)malloc(sizeof(long long)*n);
​
    for (i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }
    long long a = ssearch(arr, n, m, max);
    printf("%lld", a);
}
