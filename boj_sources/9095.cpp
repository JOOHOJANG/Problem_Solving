#include <stdio.h>
​
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int arr[100] = { 0 };
        scanf("%d", &n);
        arr[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i - 1 >= 0)
                arr[i] += arr[i - 1];
            if (i - 2 >= 0)
                arr[i] += arr[i - 2];
            if (i - 3 >= 0)
                arr[i] += arr[i - 3];
        }
        printf("%d\n", arr[n]);
    }
}
