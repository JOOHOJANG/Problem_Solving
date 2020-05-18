#include <stdio.h>
#include <stdlib.h>
int lego[1000000];
int compare(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}
int ssearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) return key;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}
int main() {
    int x, n,  i;
    while (scanf("%d", &x) != -1) {
    int flag = 0;
    x *= 10000000;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &lego[i]);
    qsort(lego, n, sizeof(int), compare);
    for (i = 0; i < n; i++){
        flag = ssearch(lego, i+1, n - 1, x - lego[i]);
        if (flag) {
            printf("yes %d %d\n", lego[i], flag);
            break;
        }
    }
    if(flag==0||n==1||n==0) printf("danger\n");
    }
}
