#include <cstdio>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <cmath>
struct M {
    int x,y;
};
M arr[100000];
bool compare(M a, M b) {
    if (a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
}
int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d %d", &arr[i].x, &arr[i].y);
    std::sort(arr, arr + n, compare);
    for (i = 0; i < n; i++)printf("%d %d\n", arr[i].x, arr[i].y);
}
