#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
​
deque<int> d;
int a;
int n, m, t;
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int cnt = 0;
        queue<pair<int, int>>q;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            cin >> a;
            q.push({ i, a });
            pq.push(a);
        }
        while (!q.empty()) {
            int idx = q.front().first;
            int val = q.front().second;
            q.pop();
            if (pq.top() == val) {
                pq.pop();
                cnt++;
                if (idx == m) {
                    cout << cnt << "\n";
                    break;
                }
            }
            else {
                q.push({ idx, val });
            }
        }
    }
}
