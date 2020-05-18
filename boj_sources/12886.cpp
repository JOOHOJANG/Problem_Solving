#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int a, b, c;
map < pair<int, pair<int, int>>, int>ma;
bool vis[501][501][501];
bool flag;
void go(int a, int b, int c) {
    if (flag) return;
    vector<int> v;
    v.emplace_back(a), v.emplace_back(b), v.emplace_back(c);
    sort(v.begin(), v.end());
    int aa = v[0], bb = v[1], cc = v[2];
    if (vis[aa][bb][cc]) return;
    vis[aa][bb][cc] = true;
    if (aa == bb && aa == cc) {
        flag = true;
        return;
    }
    if (aa != bb) {
        go(aa + aa, bb - aa, cc);
    }
    if (aa != cc) {
        go(aa + aa, bb, cc - aa);
    }
    if (bb != cc) {
        go(aa, bb + bb, cc - bb);
    }
}
int main() {
    cin >> a >> b >> c;
    go(a, b, c);
    if ((a + b + c) % 3) {
        cout << 0;
        return 0;
    }
    if (flag) cout << 1;
    else cout << 0;
}
