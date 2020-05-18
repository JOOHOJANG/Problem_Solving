#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
​
long long int s, k;
long long int arr[20];
long long int ans=1;
int main() {
    scanf("%lld %lld", &s, &k);
    for (long long int i = 0; i < k; i++) {
        arr[i] = s / k;
    }
    if (s%k != 0) {
        long long int res = s % k;
        for (long long int i = 0; i < res; i++) {
            arr[i]++;
        }
    }
    for (long long int i = 0; i < k; i++) {
        ans *= arr[i];
    }
    printf("%lld", ans);
}
