#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, m, c;
int cow[100000];
int cowcow(int key) {
    int i, cnt = 1, startpos = 0;
    for (i = 1; i < n; i++) {
        if (i - startpos < c && cow[i] <= cow[startpos] + key) continue;
        cnt += 1;
        startpos = i;
    }
    if (cnt > m) return 1;
    else return 0;
}
int main() {
    int i;
    scanf("%d %d %d", &n, &m, &c);
    for (i = 0; i < n; i++) scanf("%d", &cow[i]);
    sort(cow, cow + n);
    int left = 0, right = 1000000000;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        int flag = cowcow(mid);
        if (flag) left = mid + 1;
        else right = mid - 1;
    }
    printf("%d", left);
}
