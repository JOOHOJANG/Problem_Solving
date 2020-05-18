#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <functional>
using namespace std;
typedef pair<int, int> pii;
int n;
int m;
pii mymin(pii a, pii b) {
    if (a.second == b.second) {
        if (a.first < b.first) return a;
        else return b;
    }
    else if (a.second > b.second) return b;
    else return a;
}
struct seg {
    int lim;
    vector<pii>tree;
    void init() {
        for (lim = 1; lim <= n; lim*=2);
        tree.resize(2 * lim + 2, { 0, 2100000000 });
    }
    void update(int idx, int realid, int val) {
        idx += lim;
        while (idx) {
            if (tree[idx].second > val) {
                tree[idx].second = val;
                tree[idx].first = realid;
            }
            idx /= 2;
        }
    }
    void update2(int idx, int realid,int val) {
        idx += lim;
        tree[idx].second = val;
        tree[idx].first = realid;
        pii ret;
        ret.first = realid; ret.second = val;
        idx /= 2;
        while (idx) {
            tree[idx] = mymin(ret, mymin(tree[idx*2], tree[2*idx+1]));
            idx /= 2;
        }
    }
​
    int query(int l, int r) {
        l += lim, r += lim;
        pii ret;
        ret.first = 2100000000;
        ret.second = 2100000000;
        while (l <= r) {
            if (l % 2 == 1) ret = mymin(ret, tree[l]);
            if (r % 2 == 0) ret = mymin(ret, tree[r]);
            l = (l + 1) / 2, r = (r - 1) / 2;
        }
        return ret.first;
    }
​
};
seg s1;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> n;
    s1.init();
    int op;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s1.update(i,i,  a);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            s1.update2(a,a,  b);
        }
        else {
            cin >> a >> b;
            int ans = s1.query(a, b);
            cout << ans << "\n";
        }
    }
}
