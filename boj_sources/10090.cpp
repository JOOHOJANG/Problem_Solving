#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int n;
struct seg {
    int lim;
    vector<int> tree;
    void init() {
        for (lim = 1; lim < n; lim <<= 1);
        tree.resize(2 * lim + 2);
    }
    void update(int idx) {
        idx += lim;
        tree[idx] = 1;
        idx /= 2;
        while (idx) {
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
            idx /= 2;
        }
    }
    int query(int l, int r) {
        int ret = 0;
        l += lim, r += lim;
        while (l <= r) {
            if (l % 2 == 1) ret += tree[l];
            if (r % 2 == 0) ret += tree[r];
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
        return ret;
    }
};
seg ss;
int arr[1000050];
long long ans;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> arr[i], v.push_back(arr[i]);
    ss.init();
​
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++) arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
    for (int i = n; i >= 1; i--) {
        ans += ss.query(1, arr[i] - 1), ss.update(arr[i]);
    }
    cout << ans;
}
