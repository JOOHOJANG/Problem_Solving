#include <cstdio>
#include <algorithm>
#include <iostream>
char arr[100000];
bool compare(char a, char b) { return a > b; }
int main() {
    int cnt = 0, i;
    while (1) {
        scanf("%c", &arr[cnt]);
        if (arr[cnt] == '\n') break;
        cnt++;
    }
    for (i = 0; i < cnt; i++) arr[i] -= 48;
    std::sort(arr, arr + cnt, compare);
    if (arr[cnt - 1] != 0) {
        printf("-1");
        return 0;
    }
    int p = 0;
    for (i = 0; i < cnt-1; i++) p += arr[i];
    if (p % 3 != 0) {
        printf("-1");
        return 0;
    }
    else {
        for (i = 0; i < cnt; i++) printf("%d", arr[i]);
    }
}
