#include <cstdio>
#include <algorithm>
#include <iostream>
char a[100000];
char b[100000];
int t;
int main() {
    int i,j;
    scanf("%d", &t);
    for (j = 0; j < t; j++) {
        int upcnt = 0, dcnt = 0;
        int n;
        scanf("%d", &n);
        scanf("%s", a);
        scanf("%s", b);
        for (i = 0; i < n; i++) {
            if (a[i] == 'W' && b[i] == 'B') upcnt++;
            else if (a[i] == 'B' && b[i] == 'W') dcnt++;
        }
        printf("%d\n", upcnt < dcnt ? dcnt : upcnt);
    }
}
