#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
​
int t;
int n, m;
vector<int> dur;
vector<vector<int>> v;
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        
        cin >> n >> m;
        v.clear();
        dur.clear();
        v.resize(n + 1);
        dur.resize(n + 1);
        vector<int> indeg(n + 1, 0);
        vector<int> last(n + 1, 0);
        int a, b;
        for (int i = 1; i <= n; i++)cin >> dur[i];
        for (int i = 1; i <= m; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            indeg[b]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (!indeg[i]) {
                last[i] = dur[i];
                q.push(i);
            }
        }
        while (!q.empty()) {
            int aa = q.front(); q.pop();
            for (auto k : v[aa]) {
                last[k] = max(dur[k] + last[aa], last[k]);
                if (--indeg[k] == 0) {
                    q.push(k);
                }
            }
        }
        cin >> a;
        cout << last[a]<<"\n";
        
    }
}
