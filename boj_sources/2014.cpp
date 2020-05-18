#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using lint = long long int;
lint n, k;
map<int, int>m;
priority_queue < int, vector<int>, greater<int>> pq;
vector<lint> v;
​
int main() {
    lint Max = 0;
    cin >> k >> n;
    v.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        pq.push(v[i]);
        Max = max(v[i], Max);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        ans = pq.top(); pq.pop();
        for (int j = 0; j < k; j++) {
            cnt++;
            lint a = ans * v[j];
            //if (ans % a == 0)break;
            if (!m[a]) {
                m[a]++;
                pq.push(a);
                Max = max(Max, a);
            }
        }
    }
    cout << ans;
}
