#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int arrm1[50];
int arrm2[50];
int main() {
    int n, i, m;
    cin >> n >> m;
​
    int min = 0;
    for (i = 0; i < m; i++) scanf("%d %d", &arrm1[i], &arrm2[i]);
    sort(arrm1, arrm1 + m), sort(arrm2, arrm2 + m);
    while (n > 0) {
        if (n >= 6 && arrm1[0] < arrm2[0] * 6) {
            n -= 6;
            min += arrm1[0];
        }
        else if (n < 6 && arrm1[0] < arrm2[0] * n) {
            n -= 6;
            min += arrm1[0];
        }
        else {
            min += arrm2[0] * n;
            n = 0;
        }
    }
    printf("%d", min);
}
