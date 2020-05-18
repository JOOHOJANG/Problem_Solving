#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int res;
vector<bool> vis(10, false);
void solve(int idx, int cnt) {
    if (idx == n) {
        if (cnt != m) return;
        res++;
        return;
    }
​
    for (int i = 0; i < 10; i++) {
        if (vis[i]) {
            vis[i] = false;
            solve(idx + 1, cnt + 1);
            vis[i] = true;
            continue;
        }
        solve(idx + 1, cnt);
    }
}
​
int main() {
    int a;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> a;
        vis[a] = true;
    }
    solve(0, 0);
    cout << res;
}
