#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n;
int ans;
​
​
struct str {
    int val, idx;
};
vector<vector<str>> v(5);
​
bool compare(str a, str b) {
    if (a.val == b.val) return a.idx < b.idx;
    else return a.val > b.val;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < 5; i++)v[i].resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> v[j][i].val;
            v[j][i].idx = i;
        }
    }
    for (int i = 0; i < 5; i++) sort(v[i].begin(), v[i].end(), compare);
​
    vector<int> per = { 0, 1, 2, 3, 4 };
​
    do {
        map<int, int> ma;
        int res = 0;
        for (int i = 0; i < per.size(); i++) {
            for (auto next : v[per[i]]) {
                int val = next.val;
                int idx = next.idx;
                if (!ma[idx]) {
                    ma[idx]++;
                    res += val;
                    break;
                }
            }
        }
        ans = max(ans, res);
    } while (next_permutation(per.begin(), per.end()));
    cout << ans;
}
