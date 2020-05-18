#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int vis[9];
map<string, int> ma;
vector<int>v;
vector<int>vv;
int n, m;
void solve(int idx, int cnt) {
    if (cnt == m) {
        string str;
        for (int i = 0; i < m; i++) {
            str += (vv[i] + '0');
        }
        if (!ma[str]) {
            ma[str]++;
            for (int i = 0; i < m; i++) {
                cout << vv[i] << " ";
            }
            cout << "\n";
        }
        return;
    }
​
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            vv.push_back(v[i]);
            solve(i, cnt + 1);
            vv.pop_back();
            vis[i] = 0;
        }
    }
}
int main() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    solve(0, 0);
}
