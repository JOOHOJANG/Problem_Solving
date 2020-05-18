#include <queue>
#include <iostream> 
using namespace std;
​
int visited[100000];
int n, t, g;
​
int bfs() {
    queue<pair<int, int>>que;
    que.push(make_pair(n, 0));
    visited[n] = 1;
​
    while (!que.empty()) {
        int num = que.front().first;
        int cnt = que.front().second;
        que.pop();
​
        if (cnt > t) return -1;
        if (num == g) return cnt;
​
        int curr = num + 1;
        if (!visited[curr] && curr<100000) {
            visited[curr] = 1;
            que.push(make_pair(curr, cnt + 1));
        }
​
        if (2 * num >= 100000 || num == 0) continue;
        int temp = 2 * num;
        curr = temp;
        int digit = 1;
        while (temp)
        {
            temp /= 10;
            digit *= 10;
        }
        digit /= 10;
        curr -= digit;
        if (!visited[curr] && curr<100000) {
            visited[curr] = 1;
            que.push(make_pair(curr, cnt + 1));
        }
    }
    return -1;
}
​
int main() {
    scanf("%d %d %d", &n, &t, &g);
    int bb = bfs();
    if (bb == -1) printf("ANG");
    else printf("%d", bb);
}
