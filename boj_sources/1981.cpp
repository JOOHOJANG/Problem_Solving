#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
​
int n;
int arr[101][101];
int vis[101][101];
int mmin = 1e9 , mmax;
int ret = 1e9;
set<int> st;
int di[4] = { 1, 0, -1, 0 };
int dj[4] = { 0, -1, 0, 1 };
bool solve(int val) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>>q;
    vis[0][0] = 1;
    q.push({ 0, 0 });
    set<int> ss;
    ss.insert(arr[0][0]);
    while (!q.empty()) {
        pair<int, int> pii = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = pii.first + di[i];
            int dy = pii.second + dj[i];
            if (dx < 0 || dx >= n || dy<0 || dy >= n || vis[dx][dy]) continue;
            vis[dx][dy] = 1;
            if (arr[dx][dy] > val) continue;
            ss.insert(arr[dx][dy]);
            if (dx == n - 1 && dy == n - 1) {
                set<int>::iterator iter;
                vector<int>ans;
                for (iter = ss.begin(); iter != ss.end(); iter++)ans.push_back(*iter);
                sort(ans.begin(), ans.end());
                int mi = ans[0], ma = ans[ans.size() - 1];
                ret = min(ret, ma - mi);
                return true;
            }
            q.push({ dx, dy });
            
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            mmin = min(mmin, arr[i][j]);
            mmax = max(mmax, arr[i][j]);
            st.insert(arr[i][j]);
        }
    }
    set<int>::iterator iter;
    vector<int> ans;
    for (iter = st.begin(); iter != st.end(); iter++) ans.push_back(*iter);
    sort(ans.begin(), ans.end());
    int start = 0;
    int end = mmax - mmin;
    while (start < end) {
        int mid = (start + end) / 2;
        if (solve(mid)) end = mid - 1;
        else start = mid + 1;
    }
    cout << ret;
}
