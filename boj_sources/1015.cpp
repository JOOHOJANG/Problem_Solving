#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <string>
using namespace std;
struct M {
    int ans, val, idx;
};
M arr[50];
​
bool compare(M a, M b) {
    if (a.val != b.val) return a.val < b.val;
    return a.idx < b.idx;
}
bool compare2(M a, M b) {
    return a.idx < b.idx;
}
int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }
    sort(arr, arr + n, compare);
    for (i = 0; i < n; i++) arr[i].ans = i;
    sort(arr, arr + n, compare2);
    for (i = 0; i < n; i++) printf("%d ", arr[i].ans);
}
