#include <iostream>
#include <vector>
​
using namespace std;
int n, m;
vector<int> v;
int vis[9];
void go(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < cnt; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
​
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            v.push_back(i);
            go(cnt + 1);
            v.pop_back();
            vis[i] = false;
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        vis[i] = true;
        v.push_back(i);
        go(1);
        v.pop_back();
        vis[i] = false;
    }
}
