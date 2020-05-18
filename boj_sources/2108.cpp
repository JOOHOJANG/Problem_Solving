#include <cstdio>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <cmath>
struct M {
    int i, k;
};
int arr[500000];
M count[8001];
bool compare(M a, M b) {
    if (a.k == b.k) return a.i < b.i;
    else return a.k > b.k;
}
int main() {
    int n,i, k, sum=0;
    int min = 4001, max = -4001;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        sum += k;
        arr[i] = k;
        if (k < min) min = k;
        if (k > max) max = k;
        count[k + 4000].k++;
        count[k + 4000].i = k;
    }
    float a = (float)(sum)/n;
    printf("%.0f\n", floor(a+0.5));
    std::sort(arr, arr + n);
    printf("%d\n", arr[n / 2]);
    std::sort(count, count + 8001, compare);
    if (count[0].k == count[1].k) printf("%d\n", count[1].i);
    else printf("%d\n", count[0].i);
    printf("%d\n", max - min);
}
