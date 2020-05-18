#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> vv;
int arr[9];
int vis[9];
int n, m;
void solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < vv.size(); i++) {
            cout << vv[i] << " ";
        }
        cout << "\n";
        return;
    }
​
    for (int i = 0 ; i < v.size(); i++) {
            vv.push_back(v[i]);
            solve(cnt + 1);
            vv.pop_back();
    }
}
int main() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    solve(0);
}
