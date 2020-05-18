#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
​
int n;
pair<int, int>v[2001];
int vis[2001][2001];
int cnt;
int max(int a, int b, int c) {
    if (a >= b) {
        if (a >= c) return a;
        else return c;
    }
    if (b >= c) {
        if (b >= a) return b;
        else return a;
    }
    if (c >= a) {
        if (c >= b) return c;
        else return b;
    }
    if (c >= b) {
        if (c >= a) return c;
        else return a;
    }
    if (a >= c) {
        if (a >= b) return a;
        else return b;
    }
    if (b >= a) {
        if (b >= c) return b;
        else return c;
    }
​
}
int go(int s1, int s2) {
    int res = vis[s1][s2];
    if (res != -1) return res;
    if (s1 == n || s2 == n) return 0;
    res = 0;
    if (v[s1].first > v[s2].second) {
        res += max(go(s1 + 1, s2 + 1), go(s1 + 1, s2), go(s1, s2 + 1) + v[s2].second);
    }
    else {
        res += max(go(s1 + 1, s2 + 1), go(s1 + 1, s2));
    }
    vis[s1][s2] = res;
    return res;
}
​
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> v[i].first;
    for (int i = 0; i <n; i++)cin >> v[i].second;
    memset(vis, -1, sizeof(vis));
    int answer = go(0, 0);
​
    cout << answer;
}
