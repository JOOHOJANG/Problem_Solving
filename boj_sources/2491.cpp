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
    for (int i = 0; i < n; i++) cin >> v[i];
    s1 = s2 = v[0];
    int c1 = 1, c2 = 1;
    ans1 = ans2 = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] >= s1) {
            c1++;
            ans1 = max(ans1, c1);
            s1 = v[i];
            continue;
        }
        else {
            s1 = v[i];
            ans1 = max(ans1, c1);
            c1 = 1;
            continue;
        }
​
    }
    for (int i = 1; i < n; i++) {
        if (v[i] <= s2) {
            c2++;
            ans2 = max(ans2, c2);
            s2 = v[i];
            continue;
        }
        else {
            s2 = v[i];
            ans2 = max(ans2, c2);
            c2 = 1;
            continue;
        }
    }
​
​
​
    cout << max(ans1, ans2);
}
