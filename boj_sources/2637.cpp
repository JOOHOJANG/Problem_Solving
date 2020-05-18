#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int n, m;
vector<vector<pii>>v;
int a, b, c;
queue<int> q;
int indeg[101];
bool check[101];
int arr[101][101];
int main() {
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[b].push_back({ a, c });
        indeg[a]++;
        arr[b][a] = c;
    }
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            check[i] = true;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int aa = q.front(); q.pop();
        if (check[aa]) {
            for (auto next : v[aa]) {
                arr[next.first][aa] += arr[aa][next.first];
                if (--indeg[next.first] == 0) q.push(next.first);
            }
        }
        else {
            for (auto next : v[aa]) {
                for (int i = 1; i <= n; i++) {
                    if (check[i]) {
                        arr[next.first][i] += (next.second * (arr[aa][i]));
                    }
                }
                if (--indeg[next.first] == 0) q.push(next.first);
            }
        }
    }
​
    for (int i = 1; i <= n; i++) {
        if (check[i]) {
            cout << i << " " << arr[n][i] << "\n";
        }
    }
​
}
