#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int n;
vector<string>v, re;
long long ans;
long long like;
set<string> st;
string reverse(string str) {
    string tmp;
    for (int i = str.size() - 1; i >= 0; i--) {
        tmp += str[i];
    }
    return tmp;
}
​
struct seg {
    int lim;
    vector<int> tree;
    void init() {
        for (lim = 1; lim < n; lim *= 2);
        tree.resize(2 * lim + 2);
    }
    void update(int idx) {
        idx += lim;
        while (idx) {
            tree[idx] += 1;
            idx /= 2;
        }
    }
    int query(int l, int r) {
        l += lim, r += lim;
        int ret = 0;
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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    string tmp;
    ss.init();
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
        re.push_back(reverse(tmp));
    }
    sort(v.begin(), v.end());
    sort(re.begin(), re.end());
    int cnt=0;
    set<string>::iterator iter;
    for (int i = v.size() - 1; i >= 0; i--) {
        int idx = lower_bound(re.begin(), re.end(), reverse(v[i]))  -re.begin();
        ss.update(idx);
        like += ss.query(0, idx - 1);
    }
    cout << like;
}
