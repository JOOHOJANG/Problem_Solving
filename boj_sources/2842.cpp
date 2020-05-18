#include<stdio.h>
#include<queue>
#include <iostream>
#include<set>
#include <cstring>
using namespace std;
​
struct point {
    int y, x, v;
    char ch;
};
​
int n, visit[50][50], low = 1e9, high, kcnt, ret = 1e9;
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
point arr[50][50], s, p;
queue<point> q;
set<int>hs;
​
bool search(int l, int r) {
    memset(visit, 0, sizeof(visit));
    while (!q.empty())q.pop();
    q.push(s);
    visit[s.y][s.x] = 1;
    int cnt = 0;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (int k = 0; k < 8; k++) {
            int ny = p.y + dy[k], nx = p.x + dx[k];
            if (ny < 0 || ny == n || nx < 0 || nx == n || visit[ny][nx])continue;
            visit[ny][nx]++;
            if (arr[ny][nx].v<l || arr[ny][nx].v>r)continue;
            q.push(arr[ny][nx]);
            if (arr[ny][nx].ch == 'K') {
                cnt++;
                if (cnt == kcnt) {
                    if (ret > r - l)
                        ret = r - l;
                    return true;
                }
            }
        }
    }
    return false;
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
        cin >> arr[i][j].ch;
        arr[i][j].y = i;
        arr[i][j].x = j;
        if (arr[i][j].ch == 'K')kcnt++;
        if (arr[i][j].ch == 'P') s = arr[i][j];
    }
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
        cin >> arr[i][j].v;
        if (arr[i][j].ch != '.') {
            if (high < arr[i][j].v)high = arr[i][j].v;
            if (low > arr[i][j].v)low = arr[i][j].v;
        }
        hs.insert(arr[i][j].v);
    }
    set<int>::iterator l = hs.begin(), r = lower_bound(hs.begin(), hs.end(), high);
    while (l != hs.end() && r != hs.end() && *l <= *r && *l <= low) {
        if (search(*l, *r)) l++;
        else r++;
    }
    cout << ret;
}
​
