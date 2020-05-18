#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>>v;
int n;
int a, b, c;
int indeg[10001];
int last[10001];
int dur[10001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        dur[i] = a;
        cin >> b;
        for (int j = 0; j < b; j++) {
            cin >> c;
            v[c].push_back(i);
            indeg[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!indeg[i]) {
            q.push(i);
            last[i] = dur[i];
        }
    }
​
    while (!q.empty()) {
        int aa = q.front(); q.pop();
        for (auto k : v[aa]) {
            last[k] = max(last[k], dur[k] + last[aa]);
            if (--indeg[k] == 0)q.push(k);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, last[i]);
    }
    cout << ans;
}
