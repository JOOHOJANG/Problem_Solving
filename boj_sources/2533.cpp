#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1000001][2];
int n;
vector<vector<int>>v;
​
int dfs(int prev, int cur, int chk) {
    int& ret = dp[cur][chk];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int i = 0; i < v[cur].size(); i++) {
        int next = v[cur][i];
        if (next == prev) continue;
        if(chk){
            ret += dfs(cur, next, 0);
        }
        else {
            ret += max(dfs(cur, next, 1) + 1, dfs(cur, next, 0));
        }
    }
    return ret;
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    cout << n - max(dfs(-1, 1, 0), dfs(-1, 1, 1) + 1);
}
