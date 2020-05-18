#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define INF -210000000
using namespace std;
typedef pair<int, int> pii;
vector<int>v;
int n;
bool compare(pair<pii, int> a, pair<pii, int> b) {
    return a.second < b.second;
}
​
bool uniq(pii aa, pii bb) {
    int a = aa.first, b = aa.second, c = bb.first, d = bb.second;
    if (a != b && a != c && a != d && b != c && b != d && c != d) return true;
    else return false;
}
​
int mymax(pii aa, pii bb) {
    int a = aa.first, b = aa.second;
    int c1 = bb.first, c2 = bb.second;
    if (v[c1] + v[c2] + v[a] == v[b]) return v[b];
    else return v[a];
}
int ans = INF;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (1) {
        bool flag = false;
        cin >> n;
        if (n == 0) break;
        v.clear();
        v.resize(n);
        vector<pair<pii, int>> plus, minus;
        vector<int>m, p;
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                plus.push_back(make_pair( pii(i, j), v[i] + v[j] ));
                minus.push_back(make_pair(pii(i, j), v[i] - v[j]));
                m.push_back(v[i] - v[j]);
                p.push_back(v[i] + v[j]);
            }
        }
        sort(plus.begin(), plus.end(), compare);
        sort(minus.begin(), minus.end(), compare);
        sort(m.begin(), m.end()); sort(p.begin(), p.end());
        int size = plus.size();
        for (int i = 0; i < size; i++) {
            int val = plus[i].second;
            int lo = lower_bound(m.begin(), m.end(), val) - m.begin();
            int hi = upper_bound(m.begin(), m.end(), val) - m.begin();
            if (lo >= size) continue;
            if (minus[lo].second != val) continue;
            for (int j = lo; j < hi; j++) {
                if (minus[j].second != val) break;
                if (uniq(plus[i].first, minus[j].first)) {
                    ans = max(ans, mymax(minus[j].first, plus[i].first));
                    flag = true;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            int val = minus[i].second;
            int lo = lower_bound(p.begin(), p.end(), val) - p.begin();
            int hi = upper_bound(p.begin(), p.end(), val) - p.begin();
            if (lo >= size) continue;
            if (plus[lo].second != val) continue;
            for (int j = lo; j < hi; j++) {
                if (plus[j].second != val) break;
                if (uniq(minus[i].first, plus[j].first)) {
                    ans = max(ans, mymax(minus[i].first, plus[j].first));
                    flag = true;
                }
            }
        }
        if (flag) cout << ans << "\n";
        else cout << "no solution\n";
        ans = INF;
    }
}
