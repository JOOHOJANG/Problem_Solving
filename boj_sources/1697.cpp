#include <iostream>
#include <queue>
#define lim 200001
using namespace std;
queue<pair<int, int>>q;
int n, m;
int vis[200001];
int main() {
    cin >> n >> m;
    q.push({ n, 0 });
    while (!q.empty()) {
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();
        if (pos == m) {
            cout << time;
            return 0;
        }
        if (pos - 1 >= 0) {
            if(!vis[pos - 1]){
                vis[pos - 1] = true;
                q.push({ pos - 1, time + 1 });
            }
        }
        if (0 < pos + 1 && pos + 1 < lim) {
            if(!vis[pos + 1]){
                vis[pos + 1] = true;
                q.push({ pos + 1, time + 1 });
            }
        }
        if (0 < pos * 2 && pos * 2 < lim) {
            if (!vis[pos * 2]) {
                vis[pos * 2] = true;
                q.push({ pos * 2, time + 1 });
            }
        }
    }
}
