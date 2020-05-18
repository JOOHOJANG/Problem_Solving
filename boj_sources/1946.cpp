#include <cstdio>
#include <iostream>
#include <algorithm>
struct M {
    int x, y;
};
bool compare(M a, M b) {
    if (a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}
​
M arr[100000];
int t;
int main() {
    int i;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        int cnt = 1;
        int j;
        M min;
        int n;
        scanf("%d", &n);
        for (j = 0; j < n; j++) scanf("%d %d", &arr[j].x, &arr[j].y);
        std::sort(arr, arr + n, compare);
        min.x = arr[0].x, min.y = arr[0].y;
        for (j = 1; j < n; j++) {
            if (min.x < arr[j].x && min.y < arr[j].y) continue;
            cnt++, min = arr[j];
        }
        printf("%d\n", cnt);
    }
}
