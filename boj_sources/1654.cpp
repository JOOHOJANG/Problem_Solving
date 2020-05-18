#include <stdio.h>
#include <stdlib.h>
long long ssearch(long long int arr[],  long long int n, long long int key) {
    long long int right = 2147483648*2, left = 0;
    long long int i, sum, middle;
    while (left <= right) {
        sum = 0;
        middle = (left + right) / 2;
        for (i = 0; i < n; i++)
            sum += arr[i] / middle;
        if (sum >= key) left = middle;
        else right = middle;
        if (right - left == 1)
            break;  
    }
    sum = 0;
    for (i = 0; i < n; i++)
        sum += arr[i] / right;
    if (sum == key)
        return right;
    else
        return left;
}
int main() {
    long long int k, n, i;
    long long int sum = 0;
    scanf("%lld %lld", &k, &n);
    long long int* arrk = (long long int*)malloc(sizeof(long long int)*k);
    for (i = 0; i < k; i++)
        scanf("%lld", &arrk[i]);
    long long int mid = ssearch(arrk, k, n);
    printf("%lld", mid);
}
