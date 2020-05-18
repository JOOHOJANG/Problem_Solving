#include <stdio.h>
#include <stdlib.h>
​
int compare(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}
​
int ssearch(int arr[], int n, int key) {
    int left = 0, right = n - 1, ret = -1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] == key) return ret = middle;
        if (arr[middle] > key) right = middle - 1;
        else left = middle + 1;
    }
    return ret;
}
​
int main() {
    int a, b, i;
    int k;
    scanf("%d %d", &a, &b);
    int* arra = (int*)malloc(sizeof(int)*a);
    int* aarra = (int*)malloc(sizeof(int)*a);
    int* arrb = (int*)malloc(sizeof(int)*b);
    for (i = 0; i < a; i++) scanf("%d", &arra[i]);
    for (i = 0; i < b; i++) scanf("%d", &arrb[i]);
    qsort(arra, a, sizeof(int), compare);
    qsort(arrb, b, sizeof(int), compare);
    int cnt = 0;
    for (i = 0; i < a; i++) {
        k = ssearch(arrb, b, arra[i]);
        if (k == -1)
            aarra[cnt++] = arra[i];
    }
    if (cnt == 0)
        printf("%d", cnt);
    else {
        printf("%d\n", cnt);
        for (i = 0; i < cnt; i++)
            printf("%d ", aarra[i]);
    }
}
