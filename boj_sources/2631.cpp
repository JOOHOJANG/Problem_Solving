#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int main() {
    vector<int> v, vv;
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        int idx = lower_bound(vv.begin(), vv.end(), v[i]) - vv.begin();
        if (idx >= vv.size())vv.push_back(v[i]);
        else {
            vv[idx] = v[i];
        }
    }
    cout << n - vv.size();
}
