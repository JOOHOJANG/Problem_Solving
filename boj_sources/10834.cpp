#include <iostream>
#include <algorithm>
using namespace std;
​
int rot;
int m;
int tmp;
int c1, c2;
pair<int, int> v[1001];
int rat;
int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second >> tmp;
        rot += tmp;
    }
    int st = v[0].first;
    for (int i = 1; i < m; i++) {
        if (v[i - 1].second > v[i].first) {
            rat = v[i - 1].second / v[i].first;
            v[i].first *= rat, v[i].second *= rat;
        }
    }
    if (rot % 2) cout << 1 << " ";
    else cout << 0 << " ";
    cout << v[m - 1].second;
}
