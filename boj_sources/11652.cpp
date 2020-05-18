#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <string>
struct M {
    long long int max, flag;
};
using namespace std;
long long int arr[1000001];
int main() {
    long long int n, i, cnt = 0;
    M a;
    a.max = 0, a.flag = 0;
    scanf("%lld", &n);
    for (i = 0; i < n; ++i) scanf("%lld", &arr[i]);
    sort(arr, arr + n);
    for (i = 1; i <= n; i++) {
        cnt++;
        if (arr[i] != arr[i - 1]) {
            if (a.max < cnt) a.max = cnt, a.flag = arr[i - 1], cnt = 0;
            else cnt = 0;
        }
    }
    printf("%lld", a.flag);
}
