#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
​
int n, m;
struct seg {
    int lim;
    vector<int> tree;
    void init() {
        for (lim = 1; lim <n; lim *= 2);
        tree.resize(2 * lim + 1);
    }
    void update(int idx) {
        idx += lim;
        while (idx) {
            tree[idx]++;
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
vector<int> v[2001];
seg ss;
long long sum;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int tmp, tmp2;
    ss.init();
    for (int i = 0; i < m; i++) {
        cin >> tmp >> tmp2;
        v[tmp].push_back(tmp2);
    }
    for (int i = 1; i <= n; i++) {
        for (auto k : v[i]) {
            sum += ss.query(k + 1, n);
        
        }
        for (auto k : v[i]) {
            ss.update(k);
        }
    }
    cout << sum;
}
