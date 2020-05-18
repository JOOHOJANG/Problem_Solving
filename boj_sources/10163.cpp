#include <iostream>
using namespace std;
int t;
​
int visited[101][101];
int cnt[101];
int n, x, y,w, h;
int main() {
    cin >> n;
    for(int i  = 1 ; i<=n ; i++){
        cin >> x >> y >> w >> h;
        for (int a = x; a < x + w; a++) {
            for (int b = y; b < y + h; b++) visited[a][b] = i;
        }
    }
    for (int a = 0; a <= 100; a++)
        for (int b = 0; b <= 100; b++)
            cnt[visited[a][b]]++;
    for (int i = 1; i <= n; i++)printf("%d\n", cnt[i]);
}
