#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
​
int R, C;
queue<pii> start;
queue<pii> water;
vector<pii> vwater;
vector<pii> vstart;
char arr[51][51];
int vis[51][51];
pii dest;
int cnt;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool flag;
bool cflag;
void mul() {
    while (!water.empty()) {
        pii p = water.front();
        water.pop();
        int x = p.first;
        int y = p.second;
        vis[x][y] = 2;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || x >= R || yy < 0 || yy >= C || arr[xx][yy] == 'D' || arr[xx][yy] == 'X'||vis[xx][yy]==2)continue;
            vis[xx][yy] = 2;
            vwater.push_back(make_pair(xx, yy));
            arr[xx][yy] = '*';
        }
    }
    for (int i = 0; i < vwater.size(); i++) water.push(vwater[i]);
    vwater.clear();
    vwater.resize(0);
}
void hedge() {
    flag = false;
    while (!start.empty()) {
        pii p = start.front();
        start.pop();
        int x = p.first;
        int y = p.second;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= R || yy < 0 || yy >= C || arr[xx][yy] == 'X' || arr[xx][yy] == '*' || vis[xx][yy]) continue;
            if (xx == dest.first && yy == dest.second) cflag = true;
            flag = true;
            vstart.push_back(make_pair(xx, yy));
            vis[xx][yy] = 1;
        }
    }
    for (int i = 0; i < vstart.size(); i++) start.push(vstart[i]);
    vstart.clear();
    vstart.resize(0);
}
int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'D') dest.first = i, dest.second = j;
            if (arr[i][j] == '*') water.push(make_pair(i, j));
            if (arr[i][j] == 'S') start.push(make_pair(i, j));
        }
    }
    while (1) {
        cnt++;
        mul();
        hedge();
        if (cflag) {
            cout << cnt;
            return 0;
        }
        if (!flag) {
            cout << "KAKTUS";
            return 0;
        }
    }
    
}
