#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<long long, pair<long long, long long>> ppi;
long long n;
vector<long long> v;
​
bool compare(ppi a, ppi b) {
    if (a.second.second == b.second.second) {
        return a.second.first < b.second.first;
    }
    return a.second.second > b.second.second;
}
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n);
    for (long long i = 0; i < n; i++) {
        cin >> v[i];
    }
​
    vector<ppi> vv(n);
    for (long long i = 0; i < n; i++) {
        vv[i].first = v[i];
        long long c1 = 0, c2 = 0;
        while (v[i] != 1) {
            if (v[i] % 2 == 0) {
                c1++;
                v[i] /= 2;
            }
            else if (v[i] % 3 == 0) {
                c2++;
                v[i] /= 3;
            }
            else break;
        }
        vv[i].second.first = c1, vv[i].second.second = c2;
    }
    sort(vv.begin(), vv.end(), compare);
    
    for (int i = 0; i < n; i++) {
        cout << vv[i].first << " ";
    }
}
