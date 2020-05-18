#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<bool>> v;
​
int vis[26][26];
char arr[26][26];
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
int n;
void solve(int x, int y, int cnt) {
    vis[x][y] = 1;
    v[cnt].push_back(1);
    for (int i = 0; i < 4; i++) {
        int dx = x + di[i];
        int dy = y + dj[i];
        if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
        if (!vis[dx][dy] && arr[dx][dy]) solve(dx, dy, cnt);
    }
}
​
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            arr[i][j] -= '0';
        }
    }
​
    int cnt = 0;
    for(int i = 0 ; i<n ; i++) 
        for (int j = 0; j < n; j++) {
            if (arr[i][j] && !vis[i][j]) {
                v.push_back({});
                solve(i, j, cnt++);
            }
        }
​
    vector<int> ans;
    for (int i = 0; i < v.size(); i++) {
        ans.push_back(v[i].size());
    }
    sort(ans.begin(), ans.end());
    cout << ans.size()<<"\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}
