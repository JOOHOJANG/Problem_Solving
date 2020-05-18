#include <stdio.h>
#include <stdlib.h>
​
int compare(const void *a, const void *b)   
{
    int num1 = *(int *)a;   
    int num2 = *(int *)b;   
    if (num1 < num2)   
        return -1;    
    if (num1 > num2)   
        return 1;      
    return 0;  
}
​
int binarysearch(int arr[], int n, int key) {
    int left = 0, right = n - 1, ret = -1, mid = n / 2;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return ret = mid;
        if (key < arr[mid])
            right = mid - 1;
        else left = mid + 1;
    }
    return ret;
}
​
int main() {
    int i;
    int n, m;
    scanf("%d", &n);
    int* arrn = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &arrn[i]);
    scanf("%d", &m);
    int* arrm = (int*)malloc(sizeof(int)*m);
    for (i = 0; i < m; i++)
        scanf("%d", &arrm[i]);
​
    qsort(arrn, n, sizeof(int), compare);
​
    for (i = 0; i < m; i++) {
        int a = binarysearch(arrn, n, arrm[i]);
        if (a == -1)
            printf("0\n");
        else printf("1\n");
    }
​
}
