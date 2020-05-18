#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
bool vis[9];
vector<int> v;
void go(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = idx; i<=n; i++){
        if (!vis[i]) {
            vis[i] = true;
            v.push_back(i);
            go(i, cnt + 1);
            v.pop_back();
            vis[i] = false;
        }
    }
}
​
int main() {
    cin >> n >> m;
​
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            v.push_back(i);
            go(i, 1);
            v.pop_back();
            vis[i] = false;
        }
    }
}
