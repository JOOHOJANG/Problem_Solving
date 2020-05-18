#include <iostream>
using namespace std;
​
int p[100001];
int n, ga, ans;
​
int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}
​
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    p[x] = y;
}
int main() {
    cin >> n >> ga;
    int a;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < ga; i++) {
        cin >> a;
        if (!find(a)) break;
        ans++;
        int tmp = find(a);
        merge(tmp, tmp-1);
        
    }
    cout << ans;
}
