#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
vector<int> ans;
int main() {
    
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        int a = q.front(); q.pop();
        ans.push_back(a);
        int tmp = a % 10;
        for (int i = 0; i < tmp; i++) {
            q.push(a * 10 + i);
        }
    }
    if (n == 1022) cout << "9876543210";
    else if (n >=1023) {
        cout << -1;
    }
    else cout << ans[n];
}
