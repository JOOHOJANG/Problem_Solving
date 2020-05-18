#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int m;
struct seg {
    int lim;
    vector<int> tree;
    void init() {
        for (lim = 1; lim < n; lim *= 2);
        tree.resize(2 * lim + 2);
    }
    void update(int idx, int val) {
        idx += lim;
        tree[idx] = val;
        idx /= 2;
        while (idx) {
            tree[idx] = max(tree[2 * idx + 1], tree[2 * idx]);
            idx /= 2;
        }
    }
​
    int query(int l, int r) {
        l += lim, r += lim;
        int ret = -1;
        while (l <= r) {
            if (l % 2 == 1) ret = max(ret, tree[l]);
            if (r % 2 == 0) ret = max(ret, tree[r]);
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
        return ret;
    }
};
​
seg ss;
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int a;
    ss.init();
    for (int i = 1; i <= n; i++) {
        cin >> a;
        ss.update(i, a);
    }
    for (int i = m; i <= n - m + 1; i++) {
        cout << ss.query(i - m + 1, i + m - 1) << " ";
    }
}
