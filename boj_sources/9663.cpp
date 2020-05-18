#include <iostream>
#include <string>
​
using namespace std;
​
​
int n;
int ans;
int diag[16][16];
int column[16];
​
int confirm(int r, int c) {
    int row = r - 1, col = c - 1;
    while (row >= 0 && col >= 0) {
        if (diag[row--][col--] || column[c]) return 0;
    }
    row = r - 1, col = c + 1;
    while (row >= 0 && col < n) {
        if (diag[row--][col++] || column[c]) return 0;
    }
    column[c] = 1;
    diag[r][c] = 1;
    return 1;
}
void clear(int r, int c) {
    diag[r][c] = 0, column[c] = 0;
}
​
void dfs(int cnt) {
    if (cnt == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (confirm(cnt, i)) {
            dfs(cnt + 1);
            clear(cnt, i);
        }
    }
}
​
int main() {
    ans = 0;
    cin >> n;
    dfs(0);
    cout << ans;
}
