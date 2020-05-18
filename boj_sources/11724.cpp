#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
​
int n, m;
vector<int> adj[1001];
int visited[1001];
​
void dfs(int curr) {
   visited[curr]++;
    int sz = adj[curr].size();
   for (int i = 0; i < sz; i++) {
      int nn = adj[curr][i];
      if (!visited[nn]) dfs(nn);
   }
}
​
int main() {
   int u, v;
   int cnt=0;
   scanf("%d %d", &n, &m);
   for (int i = 0; i < m; i++) {
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
         dfs(i);
         cnt++;
      }
   }
   printf("%d", cnt);
}
