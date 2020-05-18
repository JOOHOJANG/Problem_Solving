#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int arr[100001];
int n, s;
​
int sum;
int lcnt;
int res = 1000000;
vector<int> v;
int main() {
​
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++)cin >> arr[i];
    int lo = 0, hi = 0;
    while (lo < n && hi < n) {
        if (sum < s) {
            sum += arr[hi++];
            lcnt++;
        }
        if (sum >= s) {
            res = min(lcnt, res);
            while (sum >= s) {
                sum -= arr[lo++];
                lcnt--;
                if (sum >= s)res = min(lcnt, res);
            }
            if (lo > hi) hi = lo;
        }
    }
    if (res == 1000000) cout << 0;
    else cout << res;
}
