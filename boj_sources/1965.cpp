#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
​
int main(){
    int n;
    cin >> n;
    vector<int>v(n), vv;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(vv.begin(), vv.end(), v[i]) - vv.begin();
        if (idx >= vv.size()) vv.push_back(v[i]);
        else {
            vv[idx] = v[i];
        }
    }
    cout << vv.size();
}
