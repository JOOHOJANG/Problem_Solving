#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v, v1, v2;
int ans1, ans2;
int s1, s2;
int main() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        int idx = lower_bound(v1.begin(), v1.end(), v[i]) - v1.begin();
        if (idx >= v1.size())v1.push_back(v[i]);
        else v1[idx] = v[i];
    }
    cout << n - v1.size();
}
