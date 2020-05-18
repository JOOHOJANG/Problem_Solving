#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
set<int> st;
int n, m;
vector<vector<int>> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)v[i].resize(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)cin >> v[i][j];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            st.insert(v[j][i]);
        }
        if (st.size() == i + 1) break;
    }
    vector<int> ans;
    set<int>::iterator iter;
    for (iter = st.begin(); iter != st.end(); iter++) {
        ans.push_back(*iter);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto k : ans) {
        cout << k << " ";
    }
}
