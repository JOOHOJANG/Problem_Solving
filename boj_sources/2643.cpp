#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
​
int mmax, cnt;
int n, x, y;
vector<pair<int, int>> v;
int dp[101];
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (y > x) swap(x, y);
        v[i].first = x, v[i].second = y;
    }
    sort(v.begin(), v.end());
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j > i; j--) {
            if ((v[i].first <= v[j].first && v[i].second <= v[j].second)) dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
        if (mmax < dp[i]) mmax = dp[i];
    }
    cout << mmax;
}
