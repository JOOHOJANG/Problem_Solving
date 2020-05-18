#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <functional>
#include <cmath>
#include <stack>
using namespace std;
using pii = pair<int, pair<int, int>>;
int n;
vector<pii> v;
vector<int> s;
int lim;
​
struct seg {
    vector<int>tree;
    void init() {
        for (lim = 1; lim < 1000000; lim <<= 1);
        tree.resize(lim * 2 + 1);
    }
    void update(int idx, int val) {
        idx += lim;
        while (idx) {
            tree[idx] += val;
            if (tree[idx] < 0) tree[idx] = 0;
            idx /= 2;
        }
    }
    /*int query(int l, int r) {
        int ret = 0;
        l += lim, r += lim;
        /*while (l <= r) {
            if (l % 2 == 1) ret += tree[l];
            if (r % 2 == 0) ret += tree[r];
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
        return ret;
    }*/
    int query(int val) {
        int ret = 0;
        int idx = 1;
        while (idx < 2*lim + 1) {
            if (idx >= lim && idx < lim * 2 + 1) {
                ret = idx;
                break;
            }
            if (tree[idx * 2] >= val) idx *= 2;
            else if (tree[idx * 2] < val) {
                val -= tree[idx * 2];
                idx = (idx * 2) + 1;
            }
        }
        cout << ret-lim << "\n";
        return ret-lim;
    }
};
seg ss;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int op = 0;
    ss.init();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == 2) {
            int a, b;
            cin >> a >> b;
            ss.update(a, b);
        }
        else if (op == 1) {
            int x;
            cin >> x;
            int aa = ss.query(x);
            ss.update(aa, -1);
        }
    }
}
