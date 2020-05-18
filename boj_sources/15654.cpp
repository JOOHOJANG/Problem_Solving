#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[9];
int vis[9];
int n, m;
vector<int> v;
void solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < v.size(); i++)cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            v.push_back(arr[i]);
            solve(cnt + 1); 
            v.pop_back();
            vis[i] = false;
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    sort(arr, arr + n);
    solve(0);
}
