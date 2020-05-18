#include <stdio.h>
#include <stdlib.h>
​
int arrn[100000], arrn2[100000];
​
int compare(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}
​
int search(int arr[], int n, int key) {
    int left = 0, right = n / 2;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < key) left = mid + 1;
        else right = mid;
    }
​
    return right;
}   
​
int main() {
    int n, h, i, x;
    int cnt = 0;
    int min = 200001;
    int j = 0, k = 0;
    scanf("%d %d", &n, &h);
    for (i = 0; i < n; i++) {
        if(i%2 ==0) scanf("%d", &arrn[j++]);
        else { 
            scanf("%d", &x);
            arrn2[k++] = h - x;
        }
    }
    qsort(arrn, n / 2, sizeof(int), compare);
    qsort(arrn2, n / 2, sizeof(int), compare);
    for (i = 1; i <= h; i++) {
        int fir = (n/2) - search(arrn, n, i);
        int sec = search(arrn2, n, i);
        int sum = fir + sec;
        if (sum < min) {
            min = sum;
            cnt = 0;
            cnt++;
        }
        else if (sum == min) cnt++;
    }
    printf("%d %d", min, cnt);
    
}
