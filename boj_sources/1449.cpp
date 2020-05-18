#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <string>
using namespace std;
int arr[1000];
int main() {
    int i,n, l;
    scanf("%d %d", &n, &l);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    int cnt = 1;
    int startpos = arr[0];
    for (i = 0; i < n; i++) {
        if (startpos + l - 1 < arr[i]) cnt++, startpos = arr[i];
    }
    printf("%d", cnt);
}
