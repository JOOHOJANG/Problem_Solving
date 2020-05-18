#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2100000000
using namespace std;
typedef pair<int, int> pii;
int n, m;
int vis[13];
vector<pii> c, h;
vector<int> dist;
vector<int> visit;
int tmp;
int result = INF;
void go(int idx, int cnt) {
    if (cnt == m) {
        int tmp = 0;
        for (int i = 0; i < h.size(); i++) {
            int dif = INF;
            for (int j = 0; j < c.size(); j++) {
                if (vis[j]) {
                    dif = min(dif, abs(h[i].first - c[j].first) + abs(h[i].second - c[j].second));
                }
                
            }
            tmp += dif;
            
        }
        result = min(result, tmp);
    }
    if (idx == c.size()) return;
    vis[idx] = 1;
    go(idx + 1, cnt + 1);
    vis[idx] = 0;
    go(idx + 1, cnt);
​
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    dist.resize(2 * n, INF);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            if (tmp == 1) h.push_back({ i, j });
            else if (tmp == 2) c.push_back({ i, j });
        }
    }
    go(0, 0);
​
    cout << result;
}
