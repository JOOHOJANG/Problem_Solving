#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct compare {
    bool operator()(int a, int b) { return a > b; }
};
priority_queue<int, vector<int>, compare> pq;
vector<vector<int>> v;
int indeg[32001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    int a, b;
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        indeg[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!indeg[i]) pq.push(i);
    }
    while (!pq.empty()) {
        int a = pq.top(); pq.pop();
        cout << a << " ";
        for (auto k : v[a]) {
            if (--indeg[k]==0) pq.push(k);
        }
    }
}
