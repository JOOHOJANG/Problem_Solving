#include<iostream>
#include <cstring>
#include <queue>
using namespace std;
​
int v[1001];
int adj[1001][1001];
int visited[1001];
int st, n, m;
​
void dfs(int st, int n) {
    visited[st] = 1;
    cout << st << " ";
    for (int i = 1; i <= n; i++) {
        if (adj[st][i] && !visited[i]) dfs(i, n);
    }
}
​
void bfs(int st, int n) {
    queue<int> q;
    q.push(st);
    visited[st] = 1;
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        cout << tmp << " ";
        for (int i = 1; i <= n; i++) {
            if (adj[tmp][i] && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
​
int main() {
    cin >> n >> m >> st;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    dfs(st, n);
    memset(visited, 0, sizeof(visited));
    cout << "\n";
    bfs(st, n);
}
