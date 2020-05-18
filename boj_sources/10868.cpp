#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int n, m;
struct seg {
    int lim;
    vector<int> tree;
​
    void init() {
        for (lim = 1; lim < n; lim *= 2);
        tree.resize(2 * lim + 2);
    }
​
    void update(int idx, int val) {
        idx += lim;
        tree[idx] = val;
        idx /= 2;
        while (idx) {
            tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
            idx /= 2;
        }
    }
​
    int query(int l, int r) {
        l += lim, r += lim;
        int ret = 2100000000;
        while (l <= r) {
            if (l % 2 == 1) ret = min(ret, tree[l]);
            if (r % 2 == 0) ret = min(ret, tree[r]);
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
​
        return ret;
    }
};
​
seg ss;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ss.init();
​
    int a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        ss.update(i, a);
    }
    int b, c;
    for (int i = 0; i < m; i++) {
        cin >> b >> c;
        cout << ss.query(b, c)<<"\n";
    }
​
}
