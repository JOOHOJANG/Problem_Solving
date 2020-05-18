#include <cstdio>
#include <algorithm>
#include <iostream>
​
int arr[50];
int main() {
    int  area;
    std::cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    std::sort(arr, arr + 4);
    area = arr[0] * arr[2];
    printf("%d", area);
}
