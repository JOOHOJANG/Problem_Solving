#include <iostream>
using namespace std;
int n, m;
int vis[9];
int arr[9];
void solve(int cnt) {
    if (cnt == m ) {
        for (int i = 0; i < m; i++)
            cout << arr[i]+1 << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
            arr[cnt] = i;
            solve(cnt + 1);
    }
}
int main() {
    cin >> n >> m;
    solve(0);
}
