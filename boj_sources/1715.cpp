#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
​
int main() {
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }
    int ans = 0;
    while (!pq.empty()) {
        int a = pq.top(); pq.pop();
        if (pq.size() == 0) break;
        int b = pq.top(); pq.pop();
        ans += a;
        ans += b;
        pq.push(a + b);
    }
    cout << ans;
}
