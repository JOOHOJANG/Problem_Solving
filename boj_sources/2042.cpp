#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using lli = long long int;
lli n, m, k;
vector<lli> tr;
vector<lli> a;
lli init(vector<lli>& tr, vector<lli>& a, lli x, lli s, lli e) {
    if (s == e) return tr[x] = a[s];
    else {
        return tr[x] = init(tr, a, x<<1, s, (s + e) / 2)
            + init(tr, a, (x<<1)+1, (s + e) / 2 + 1, e);
    }
}
​
lli sum(vector<lli> &tr, lli x, lli s, lli e, lli l, lli r) {
    if (l > e || r < s) return 0;
    else if (l <= s && e<=r) return tr[x];
    else {
        return sum(tr, x << 1, s, (s + e) / 2, l, r)
            + sum(tr, (x << 1) + 1, (s + e) / 2 + 1, e, l, r);
    }
}
​
void update(vector<lli>&tr, lli x, lli s, lli e, lli i, lli dx) {
    if (i<s || i>e) return;
    tr[x] += dx;
    if (s != e) {
        update(tr, x<<1, s, (s + e) / 2, i, dx);
        update(tr, (x<<1)+ 1, (s + e) / 2 + 1, e, i, dx);
    }
}
​
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
​
    lli h = ceil(log2(n));
    a.resize(n);
    tr.resize(1<<++h);
    for (lli i = 0; i < n; i++) {
        cin >> a[i];
    }
​
    init(tr, a, 1, 0, n - 1);
​
    for (lli i = 0; i < m + k; i++) {
        lli op = 0;
        cin >> op;
        if (op == 1) {
            lli x, r;
            cin >> r>> x;
            lli dx = x - a[r - 1];
            a[r - 1] = x;
            update(tr, 1, 0, n - 1, r - 1, dx);
        }
        else if (op == 2) {
            lli b, c;
            cin >> b >> c;
            cout << sum(tr, 1, 0, n - 1, b - 1, c - 1)<<"\n";
        }
    }
}
