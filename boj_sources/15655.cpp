#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int arr[9];
int vis[9];
int n, m;
void solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
​
    for (int i = 0; i < v.size(); i++) {
        if (!vis[i] && v[i]>=arr[cnt-1]) {
            vis[i] = 1;
            arr[cnt] = v[i];
            solve(cnt + 1);
            vis[i] = 0;
        }
    }
}
int main() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    solve(0);
}
​
