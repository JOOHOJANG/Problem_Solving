#include <cstdio>
#include <algorithm>
#include <iostream>
int arr[3];
char abc[3];
int main() {
    int i;
    std::cin >> arr[0] >> arr[1] >> arr[2] >> abc;
    std::sort(arr, arr + 3);
    for (i = 0; i < 3; i++) {
        switch (abc[i]) {
            case 'A': 
                printf("%d ", arr[0]);
                break;
            case 'B':
                printf("%d ", arr[1]);
                break;
            case 'C':
                printf("%d ", arr[2]);
                break;
            default:
                break;
        }
    }
}
