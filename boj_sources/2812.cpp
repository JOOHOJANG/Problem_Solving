#include <cstdio>
#include <algorithm>
#include <iostream>
char arr[500001];
​
int main() {
    int n, k, i;
    int cnt = 1;
    scanf("%d %d %c", &n, &k, &arr[0]);
    for (i = 1; i < n; i++) {
        scanf("%c", &arr[cnt]);
        while (k && cnt && arr[cnt - 1] < arr[cnt]) {
            arr[cnt - 1] = arr[cnt];
            arr[cnt] = 0;
            k--;
            cnt--;
        }
        cnt++;
    }
    while (k--) {
        arr[--cnt] = 0;
    }
    printf("%s", arr);
}
