#include <stdio.h>
#include <stdlib.h>
​
int ssearch(int arr[], int n, int key,int r) {
    int left = 0, right = r, sum = 0, middle = 0, i, max = 0;
    while (left <= right) {
        sum = 0;
        middle = (left + right) / 2;
        for (i = 0; i < n; i++) {
            if (arr[i] < middle) sum += arr[i];
            else sum += middle;
        }
        if (middle > max && sum <= key) max = middle;
        if (sum > key) right = middle-1;
        else left = middle+1;
    }
    return max;
}
​
int main() {
    int n, i, budget, max = 0,  sum = 0;
    scanf("%d", &n);
    int* arrn = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++){
        scanf("%d", &arrn[i]);
        if (arrn[i] >= max) max = arrn[i];
        sum += arrn[i];
    }
    scanf("%d", &budget);
    if (budget >= sum) {
        printf("%d", max);
        return 0;
    }
    int a = ssearch(arrn, n, budget, max);
    printf("%d", a);
}
