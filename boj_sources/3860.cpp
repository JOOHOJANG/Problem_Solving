#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 2100000000
using namespace std;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> ppi;
vector<ppi> v[31][31];
bool grave[31][31];
bool hole[31][31];
int w, h,e, g;
int X1, X2, Y1, Y2, t;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int dist[31][31];
int cnt;
​
void set() {
    memset(grave, false, sizeof(grave));
    memset(hole, false, sizeof(hole));
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 31; j++)
            v[i][j].clear(), v[i][j].resize(0);
    }
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 31; j++) {
            if (i == 0 && j == 0)continue;
            dist[i][j] = MAX;   
        }
    }
    dist[0][0] = 0;
}
​
void solve() {
    bool cycle = false;
    for(int z= 0 ; z<w*h ; z++){
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                for (auto k : v[i][j]) {
                    
                    int ii = k.first.first; 
                    int jj = k.first.second;
                    int val = k.second;
                    if (dist[i][j] != MAX && dist[ii][jj] > dist[i][j] + val) {
                        if (z == w*h-1) cycle = true;
                        dist[ii][jj] = dist[i][j] + val;
                    }
                }
            }
        }
    }
    if (cycle) {    
        cout << "Never" << "\n";
        return;
    }
    else if (dist[w - 1][h - 1] == MAX) {
        cout << "Impossible\n";
        return;
    }
    else {
        cout << dist[w - 1][h - 1] << "\n";
        return;
    }
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (1) {
        set();
        cin >> w >> h;
        if (!w&& !h) return 0;
        cin >> g;
        for (int i = 0; i < g; i++) {
            cin >> X1 >> Y1;
            grave[X1][Y1] = true;
        }
        cin >> e;
        for (int i = 0; i < e; i++) {
            cin>>X1 >> Y1 >> X2 >> Y2 >> t;
            hole[X1][Y1] = true;
            v[X1][Y1].push_back({ { X2,Y2 }, t });
        }
​
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (i == w - 1 && j == h - 1) continue;
                if (grave[i][j] || hole[i][j]) continue;
                for (int k = 0; k < 4; k++) {
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if (grave[ii][jj] || ii < 0 || ii >= w || jj < 0 || jj >= h) continue;
                    v[i][j].push_back({ {ii, jj}, 1 });
                }
            }
        }
        solve();
​
    }
}
