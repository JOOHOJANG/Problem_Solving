#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
long long n, m;
struct seg {
    long long lim;
    vector<long long> tree;
    void init() {
        for (lim = 1; lim < n; lim <<= 1);
        tree.resize(2 * lim + 1);
    }
​
    void update(long long idx, long long val) {
        idx += lim;
        long long before = tree[idx];
        while (idx) {
            tree[idx] += (val-before);
            idx /= 2;
        }
    }
​
    long long query(long long l, long long r) {
        long long ret = 0;
        l += lim; r += lim;
        while (l <= r) {
            if (l % 2 == 1) ret += tree[l];
            if (r % 2 == 0) ret += tree[r];
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
        return ret;
    }
};
seg ss;
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
​
    cin >> n >> m;
    ss.init();
    for (long long i = 0; i < m; i++) {
        long long op;
        cin >> op;
        if (op == 1) {
            long long a, b;
            cin >> a >> b;
            ss.update(a , b);
        }
        else {
            long long a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            cout << ss.query(a, b) << "\n";
        }
    }
}
