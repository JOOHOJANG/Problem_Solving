#include <iostream>
using namespace std;
int n, m;
int vis[9];
int arr[9];
void solve(int idx ,int cnt) {
    if (cnt == m ) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = (cnt==0) ? 1:arr[cnt-1]; i <= n; i++) {
            arr[cnt] = i;
            solve(idx, cnt + 1);
    }
}
int main() {
    cin >> n >> m;
    solve(0, 0);
}
