#include <iostream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
int n;
priority_queue<int, vector<int>, less<int>> pq;
int a;
int x;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a != 0) {
            pq.push(a);
        }
        else {
            if (!pq.empty()) {
                x = pq.top();
                pq.pop();
                cout << x << "\n";
            }
            else cout << 0 << "\n";
        }
    }
}
