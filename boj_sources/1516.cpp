#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int n, a;
queue<int>q;
int ind[501];
vector<vector<int>>v;
int val[501];
int last[501];
int main() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        val[i] = a;
        while (1) {
            cin >> a;
            if (a == -1) break;
            ind[i]++;
            v[a].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            last[i] = val[i];
        }
    }
​
    while (!q.empty()) {
        int a = q.front(); q.pop();
        for (auto next : v[a]) {
            last[next] = max(last[next], val[next] + last[a]);
            if (--ind[next] == 0)q.push(next);
        }
    }
    for (int i = 1; i <= n; i++)cout << last[i] << "\n";
}
