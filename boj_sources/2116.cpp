#include <iostream>
using namespace std;
int len;
int dice[10001][6];
int mmax;
​
int find(int cnt, int cur) {
    int pass, max=0;
    if (cur == 0) pass = 5;
    else if (cur == 1) pass = 3;
    else if (cur == 2) pass = 4;
    else if (cur == 3) pass = 1;
    else if (cur == 4) pass = 2;
    else pass = 0;
    for (int i = 0; i < 6; i++) {
        if (i == cur || i == pass) continue;
        if (dice[cnt][i] > max) max = dice[cnt][i];
    }
    return max;
}
​
void dfs(int cnt, int up, int sum) {
    if (cnt >= len) {
        if (mmax < sum) mmax = sum;
        return;
    }
    int cur, cnum, next=0;
    if (up == 0) cur = 5;
    else if (up == 1) cur = 3;
    else if (up == 2) cur = 4;
    else if (up == 3) cur = 1;
    else if (up == 4) cur = 2;
    else cur = 0;
    cnum = dice[cnt][cur];
    for (int i = 0; i < 6; i++) {
        if (dice[cnt + 1][i] == cnum) {
            next = i;
            break;
        }
    }
    int m = find(cnt+1, next);
    dfs(cnt + 1, next, sum + m);
}
​
int main() {
    cin >> len;
    for(int i = 0 ; i<len ; i++)
        for (int j = 0; j < 6; j++) {
            cin >> dice[i][j];
        }
    for (int i = 0; i < 6; i++) {
        int m = find(0, i);
        dfs(0, i, m);
    }
    cout << mmax;
}
