#include <cstdio>
#include <algorithm>
#include <iostream>
long long int city[100000];
long long int gas[100000];
int main() {
    long long int n, i;
    long long int cost = 0;
    long long int cnt = 0;
    scanf("%lld", &n);
    for (i = 0; i < n - 1; i++)scanf("%lld", &city[i]);
    for (i = 0; i < n; i++) scanf("%lld", &gas[i]);
    cost = city[0] * gas[0];
    int startpos = gas[0];
    for (i = 1; i < n - 1; i++) {
        if (gas[i] < startpos) cost += city[i] * gas[i], startpos = gas[i];
        else cost += startpos * city[i];
    }
    printf("%lld", cost);
}
