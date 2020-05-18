#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
string N[1000];
​
int compare(const string& a, const string& b) {
    int i;
    int asize = a.length();
    int bsize = b.length();
    if (asize != bsize)return asize < bsize;
​
    int asum = 0, bsum = 0;
    for (i = 0; i < asize; i++) {
        if (a[i] <= '9' && a[i] >= '0') asum += a[i] - '0';
        if (b[i] <= '9' && b[i] >= '0') bsum += b[i] - '0';
    }
    if (asum != bsum) return asum < bsum;
​
    return a < b;
}
​
int main() {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> N[i];
    }
    stable_sort(N, N + n, compare);
    for (i = 0; i < n; i++) cout << N[i] << "\n";
}
