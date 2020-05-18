#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int n, m;
​
vector<vector<int>> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.resize(n + 1);
    vector<int> indeg(n + 1, 0);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a;
        vector<int> vv;
        cin >> b;
        for (int j = 1; j < a; j++) {
            cin >> c;
            v[b].push_back(c);
            indeg[c]++;
            b = c;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!indeg[i])q.push(i);
    }
    
    vector<int> ans;
    while (!q.empty()) {
        int aa = q.front(); q.pop();
        ans.push_back(aa);
        for (auto k : v[aa]) {
            if (--indeg[k] == 0) q.push(k);
        }
    }
    if (ans.size() != n) cout << 0;
    else {
        for (int i = 0; i < ans.size(); i++)cout << ans[i] << "\n";
    }
}
