#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long int x, y;
long long int ans;
long long int lo, hi, mid;
int main() {
    cin >> x >> y;
    ans = 100*y / x;
    if (ans>=99) {
        cout << -1;
        return 0;
    }
    long long int lo = 0;
    long long int hi = 1000000000;
    long long int mid = 0;
    while (lo<=hi) {
        mid = (lo + hi) / 2;
        long long int rat = 100 * (y + mid) / (x + mid);
        if (rat > ans) hi = mid-1;
        else lo = mid+1;
    }
    cout << lo;
}
