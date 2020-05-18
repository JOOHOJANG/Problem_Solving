#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
​
int n, m;
int first, second;
vector<int>fam[100];
int visited[100];
​
int bfs() {
    queue<int>que;
    que.push(first);
​
    while (!que.empty()) {
        int curr = que.front();
        que.pop();
​
        if (curr == second) 
            return visited[second];
        int sz = fam[curr].size();
        for (int i = 0; i < sz; i++) {
            int next = fam[curr][i];
            if (visited[next] == 0) {
                que.push(next);
                visited[next] = visited[curr] + 1;
            }
        }
    }
    return -1;
}
​
int main() {
    scanf("%d", &n);
    scanf("%d %d", &first, &second);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        fam[x].push_back(y);
        fam[y].push_back(x);
    }
    int aa = bfs();
    printf("%d", aa);
}
