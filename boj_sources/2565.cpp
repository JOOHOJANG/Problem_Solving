#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int main(){
    int n;
    cin >> n;
    vector<pii>v(n);vector<int> vv;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(vv.begin(), vv.end(), v[i].second) - vv.begin();
        if (idx >= vv.size()) vv.push_back(v[i].second);
        else {
            vv[idx] = v[i].second;
        }
    }
    cout << n-vv.size();
}
