#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>>v;
int n;
int dp[10001];
int maxx[10001];
int vis[10001];
​
void dfs(int cur) {
    vis[cur] = 1;
    int max1 = 0, max2 = 0;
    for (auto k : v[cur]) {
        int next = k.first; 
        int val = k.second;
        if (vis[next]) continue;
        dfs(next);
​
        if (max1 < maxx[next] + val) {
            max2 = max1;
            max1 = maxx[next] + val;
        }
        else if (max2 < maxx[next] + val) {
            max2 = maxx[next] + val;
        }
​
        dp[cur] = max(dp[cur], max1 + max2);
        dp[cur] = max(dp[cur], dp[next]);
        maxx[cur] = max(maxx[cur], max1);
    }
}
int main() {
    cin >> n;
    int a, b, c;
    v.resize(n+1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    dfs(1);
    cout << dp[1];
}
