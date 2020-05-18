#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int>v;
vector<int> vv;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(vv.begin(), vv.end(), v[i]) - vv.begin();
        if (idx >= vv.size()) {
            vv.push_back(v[i]);
        }
        else {
            vv[idx] = v[i];
        }
    }
    cout << vv.size();
}
