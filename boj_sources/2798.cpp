#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
int main() {
    int ans = 0;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v [i];
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int t = v[i] + v[j] + v[k];
                if (ans < t && t <= m) {
                    ans = t;
                }
            }
        }
    }
    cout << ans;
}
