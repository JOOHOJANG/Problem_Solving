#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
​
struct s {
    int dis, clip, time;
};
int vis[2001][2001];
int n;
queue<s> q;
int main() {
    cin >> n;
    
    q.push({ 1, 0, 0     });
    while (!q.empty()) {
        int dis = q.front().dis;
        int clip = q.front().clip;
        int time = q.front().time;
        q.pop();
        if (dis == n) {
            cout << time;
            return 0;
        }
​
        if (0 < dis && dis < 1002) {
            if (!vis[dis][dis]) {
                vis[dis][dis] = true;
                q.push({ dis, dis, time + 1 });
            }
​
            if (0 < dis + clip && dis + clip < 1002) {
                if(!vis[dis+clip][clip]){
                    vis[dis + clip][clip] = true;
                    q.push({ dis + clip, clip, time + 1 });
                }
            }
​
            if (!vis[dis - 1][clip]) {
                vis[dis - 1][clip] = true;
                q.push({ dis - 1, clip, time + 1 });
            }
            
        }
    }
}
