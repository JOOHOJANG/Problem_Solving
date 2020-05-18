#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int n;
struct seg {
    int lim;
    vector<int>tree;
    void init() {
        for (lim = 1; lim < n; lim <<= 1);
        tree.resize(2 * lim + 2);
    }
    void update(int idx, int val) {
        idx += lim;
        while (idx) {
            tree[idx] += val;
            idx /= 2;
        }
    }
​
    int find(int val) {
        int idx = 1;
        while (idx < lim) {
            if (tree[idx * 2] >= val) idx *= 2;
            else if (tree[idx * 2] < val) {
                val -= tree[idx * 2];
                idx = (idx * 2) + 1;
            }
        }
        return idx - lim;
    }
};
int m;
seg ss;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    ss.init();
    int op, a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        ss.update(i, a);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            ss.update(a, b);
        }
        else {
            cin >> a;
            cout << ss.find(a) << "\n";
        }
    }
}
