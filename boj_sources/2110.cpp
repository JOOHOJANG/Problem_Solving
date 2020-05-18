#include <stdio.h>
#include <stdlib.h>
​
int compare(const void * a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}
​
int ssearch(int arr[], int n, int key) {
    int left = 1, right = arr[n - 1] - arr[0], i;
    
    int ret = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 1;
        int start = arr[0];
        for (i = 1; i < n; i++) {
            if (arr[i] - start >= mid) {
                cnt++;
                start = arr[i];
            }
        }
        if (cnt >= key) {
            ret = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return ret;
}
​
int main() {
    int n, c, i;
    scanf("%d %d", &n, &c);
    int* arrn = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &arrn[i]);
    qsort(arrn, n, sizeof(int), compare);
    int a = ssearch(arrn, n, c);
    printf("%d", a);
}
