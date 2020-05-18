#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <functional>
using namespace std;
int n;
int m;
struct seg {
    int lim;
    vector<int>tree;
    void init() {
        for (lim = 1; lim <= n; lim*=2);
        tree.resize(2 * lim + 2);
    }
    void update1(int idx, int val) {
        idx += lim;
        tree[idx] = val;
        idx /= 2;
        while (idx) {
            tree[idx] = min(tree[idx], val);
            idx /= 2;
        }
    }
​
    void update2(int idx, int val) {
        idx += lim;
        while (idx) {
            tree[idx] = max(tree[idx], val);
            idx /= 2;
        }
    }
​
    int query1(int l, int r) {
        l += lim, r += lim;
        int ret = 0;
        while (l <= r) {
            if (l % 2 == 1) ret = min(ret, tree[l]);
            if (r % 2 == 0) ret = min(ret, tree[r]);
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
        return ret;
    }
    int query2(int l, int r) {
        l += lim, r += lim;
        int ret = 0;
        while (l <= r) {
            if (l % 2 == 1) ret = max(ret, tree[l]);
            if (r % 2 == 0) ret = max(ret, tree[r]);
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
        return ret;
    }
};
​
struct seg1 {
    int lim;
    vector<int>tree;
    void init() {
        for (lim = 1; lim <= n; lim *= 2);
        tree.resize(2 * lim + 2, 2100000000);
    }
    void update1(int idx, int val) {
        idx += lim;
        while (idx) {
            tree[idx] = min(tree[idx], val);
            idx /= 2;
        }
    }
​
    void update2(int idx, int val) {
        idx += lim;
        while (idx) {
            tree[idx] = max(tree[idx], val);
            idx /= 2;
        }
    }
​
    int query1(int l, int r) {
        l += lim, r += lim;
        int ret = 2100000000;
        while (l <= r) {
            if (l % 2 == 1) ret = min(ret, tree[l]);
            if (r % 2 == 0) ret = min(ret, tree[r]);
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
        return ret;
    }
    int query2(int l, int r) {
        l += lim, r += lim;
        int ret = 0;
        while (l <= r) {
            if (l % 2 == 1) ret = max(ret, tree[l]);
            if (r % 2 == 0) ret = max(ret, tree[r]);
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
        return ret;
    }
};
seg s2;
seg1 s1;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> n >> m;
    s1.init(); s2.init();
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s1.update1(i, a);
        s2.update2(i, a);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        int mi = s1.query1(a, b);
        int ma = s2.query2(a, b);
        cout << mi << " " << ma << "\n";
    }
}
