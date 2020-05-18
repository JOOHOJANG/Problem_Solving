#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, t;
vector<int> sp;
vector<pair<int, pair<int, int>>>v;
int arr[1001][1001];
int dist(int a, int b, int c, int d) {
    return abs(abs(a - c) + abs(b - d));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    int a, b, c;
    v.push_back({});
    int m;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        v.push_back({ a, {b,c} });
    }
​
    for (int i = 0; i <= n; i++)for (int j = 0; j <= n; j++)arr[i][j] = 100000000;
    for (int i = 1; i <= n; i++) {
        int x = v[i].second.first;
        int y = v[i].second.second;
        int f1 = v[i].first;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int xx = v[j].second.first;
            int yy = v[j].second.second;
            int f2 = v[j].first;
            int dst = dist(x, y, xx, yy);
            if (f1 && f2) {
                if (dst > t) dst = t;
            }
            arr[i][j] = dst;
        }
    }
​
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
    cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << arr[a][b] << "\n";
    }
}
