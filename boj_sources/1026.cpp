#include <cstdio>
#include <algorithm>
#include <iostream>
int a[50];
int b[50];
bool compare(int a, int b) { return a > b; }
int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    std::sort(a, a + n);
    std::sort(b, b + n, compare);
    int cost = 0;
    for (i = 0; i < n; i++) {
        cost += a[i] * b[i];
    }
    printf("%d", cost);
}
