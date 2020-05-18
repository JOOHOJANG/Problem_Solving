#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using lint = long long int;
int n, m, t;
int a[1001];
int b[1001];
vector<lint> v1, v2;
int main() {
    cin >> t >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];
​
    for (int i = 0; i < n; i++) {
        lint sum =0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            v1.push_back(sum);
        }
    }
    for (int i = 0; i < m; i++) {
        lint sum = 0;
        for (int j = i; j < m; j++) {
            sum += b[j];
            v2.push_back(sum);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
​
    lint result = 0, low = 0, high = 0;
    for (int i = 0; i < v1.size(); i++) {
        low = lower_bound(v2.begin(), v2.end(), t - v1[i]) - v2.begin();
        high = upper_bound(v2.begin(), v2.end(), t - v1[i]) - v2.begin();
​
        result += high - low;
    }
    cout << result;
}
