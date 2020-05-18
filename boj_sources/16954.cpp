#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
char arr[9][9];
queue < pair<int, int>>q;
int di[9] = { 0, 1, 1, 1, 0, -1, -1, -1,0 };
int dj[9] = { 1, 1, 0, -1, -1, -1, 0, 1 ,0};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> arr[i][j];
        }
    }
    arr[7][0] = '*';
    vector<pair<int, int>>v;
    v.push_back({ 7, 0 });
    int cnt = 0;
    while (cnt < 8) {
        queue<pair<int, int>>q;
        for (int i = v.size()-1; i >= 0; i--) {
            int x = v[i].first; 
            int y = v[i].second;
            if(arr[x][y] != '#')q.push(v[i]);
            v.pop_back();
        }
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 9; i++) {
                int xx = x + di[i];
                int yy = y + dj[i];
                if (xx < 0 || xx >= 8 || yy < 0 || yy >= 8) continue;
                if (arr[xx][yy] == '#')continue;
                v.push_back({ xx, yy });
            }
        }
​
        for (int i = 6; i >= 0; i--) {
            for (int j = 0; j < 8; j++) {
                if (arr[i][j] == '#') {
                    arr[i + 1][j] = '#';
                    arr[i][j] = '.';
                }
            }
        }
        cnt++;
    }
    if (v.size() > 0) cout << 1;
    else cout << 0;
}
