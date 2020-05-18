#include <iostream>
#include <algorithm>
#include <vector>
​
using namespace std;
int n;
struct seg {
    int lim;
    vector<long long> tree;
​
    void init() {
        for (lim = 1; lim < n; lim *= 2);
        tree.resize(2 * lim + 2, 1);
    }
    void update(int idx, int val) {
        int t = idx;
        idx += lim;
        if (tree[idx] == 0 && val == 0) return;
        long long tmp = tree[idx];
        idx /= 2;
        if (tmp) {
            while (idx) {
                tree[idx] /= tmp;
                idx /= 2;
            }
        }
        else if (!tmp && val) {
            idx = t + lim;
            while (idx) {
                tree[idx] = 1;
                idx /= 2;
            }
        }
        idx = t + lim;
        tree[idx] = val;
        idx /= 2;
        while (idx) {
            tree[idx] = (tree[idx * 2] * tree[2 * idx + 1]) % 1000000007;
            idx /= 2;
        }
    }
​
    long long query(int l, int r) {
        long long ret = 1;
        l += lim, r += lim;
        while (l <= r) {
            if (l % 2 == 1) ret = (ret * tree[l]) % 1000000007;
            if (r % 2 == 0) ret = (ret * tree[r]) % 1000000007;
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
        return ret;
    }
};
seg ss;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int m, k;
    cin >> m >> k;
    int a, b, c;
    ss.init();
    for (int i = 0; i < n; i++) {
        cin >> a;
        ss.update(i, a);
    }
    for (int i = 0; i < m + k; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            ss.update(b - 1, c);
        }
        else {
            cin >> b >> c;
            cout << ss.query(b - 1, c - 1)<<"\n";
        }
    }
}
