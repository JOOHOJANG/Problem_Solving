#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n, m;
struct seg {
    long long lim;
    vector<long long>tree;
    void init() {
        for (lim = 1; lim < n; lim <<= 1);
        tree.resize(2 * lim + 1);
    }
    void update(long long idx, long long val) {
        idx += lim;
        while (idx) {
            tree[idx] += val;
            idx /= 2;
        }
    }
​
    long long query(long long l, long long r) {
        l += lim, r += lim;
        long long ret = 0;
        while (l <= r) {
            if (l % 2 == 1) ret += tree[l];
            if (r % 2 == 0) ret += tree[r];
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
        return ret;
    }
};
​
long long myabs(long long a) {
    if (a < 0) return -a;
    else return a;
}
vector<long long>v;
seg ss;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ss.init();
    long long tmp;
    for (long long i = 0; i < n; i++) {
        cin >> tmp;
        if (i % 2 == 0)ss.update(i, tmp);
        else ss.update(i, -tmp);
    }
    for (long long i = 0; i < m; i++) {
        long long op, a, b;
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            cout << abs(ss.query(a - 1, b - 1))<<"\n";
        }
        else {
            cin >> a >> b;
            if ((a - 1) % 2 == 0) ss.update(a - 1, b);
            else ss.update(a - 1, -b);
        }
    }
}
