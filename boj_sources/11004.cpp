#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int arr[5000000];
int main() {
    int n, i, k;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    printf("%d", arr[k - 1]);
}
