#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v1, v2;
int ans;
​
void go(int idx, int sum) {
    if (idx > n) {
        ans = max(ans, sum);
        return;
    }
    if (idx + v1[idx] > n+1) {
        
        go(idx + 1, sum);
    }
    else {
        go(idx + 1, sum);
        go(idx + v1[idx], sum + v2[idx]);
    }
​
}
​
int main() {
    cin >> n;
    v1.resize(n+1), v2.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v1[i] >> v2[i];
    }
​
    go(1, 0);
    cout << ans;
​
}
