#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <functional>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
using pii = pair<int, pair<int, int>>;
int n;
vector<pii> v;
vector<int> s;
int lim;
bool compare(pii a, pii b) {
    return a.second.second < b.second.second;
}
bool compare2(pii a, pii b) {
    return a.second.first < b.second.first;
}   
struct seg {
    int lim;
    vector<int>tree;
    void init() {
        for (lim = 1; lim < n; lim <<= 1);
        tree.resize(lim * 2 + 1);
    }
    void update(int idx, int val) {
        idx += lim;
        while (idx) {
            tree[idx] += val;
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
seg ss;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
​
    cin >> n;
    v.resize(n);
    ss.init();
    for (int i = 0; i < n; i++) {
        cin >> v[i].second.second;
        v[i].second.first = i;
    }
    sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < n; i++) {
        if (i == 0) { 
            v[i].first = v[i].second.first + 1;
            continue;
        }
​
        ss.update(v[i-1].second.first, 1);
        int ans = ss.query(0, v[i].second.first);
        v[i].first = v[i].second.first + 1 - ans;
​
    }
​
    sort(v.begin(), v.end(), compare2);
    for (int i = 0; i < n; i++)cout << v[i].first << "\n";
}
