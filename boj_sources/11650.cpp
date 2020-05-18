#include <cstdio>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct P {
    int x, y;
};
P arr[100000];
bool comp(P a, P b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
​
int main(){
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d %d", &arr[i].x, &arr[i].y);
    sort(arr, arr + n, comp);
    for (i = 0; i < n; i++) printf("%d %d\n", arr[i].x, arr[i].y);
}
