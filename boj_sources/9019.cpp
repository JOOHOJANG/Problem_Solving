#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int t;
int a, b;
int visited[10000];
string bfs() {
​
    queue<pair<int, string>>que;
    que.push(make_pair(a, ""));
    visited[a] = 1;
        
    while (!que.empty()) {
        int n = que.front().first;
        string cha = que.front().second;
        que.pop();
        if (n == b) return cha;
​
        int curr = (2 * n) % 10000;
        if (!visited[curr]) {
            visited[curr] = 1;
            que.push(make_pair(curr, cha + "D"));
        }
​
        curr = n - 1 < 0 ? 9999 : n - 1;
        if (!visited[curr]) {
            visited[curr] = 1;
            que.push(make_pair(curr, cha + "S"));
        }
​
        curr = ((n % 1000) * 10) + (n / 1000);
        if (!visited[curr]) {
            visited[curr] = 1;
            que.push(make_pair(curr, cha + "L"));
        }
​
        curr = ((n % 10) * 1000) + (n / 10);
        if (!visited[curr]) {
            visited[curr] = 1;
            que.push(make_pair(curr, cha + "R"));
        }
    }
}
​
int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        memset(visited, 0, sizeof(visited));
        scanf("%d %d", &a, &b);
        cout << bfs() << "\n";
    }
    
}
