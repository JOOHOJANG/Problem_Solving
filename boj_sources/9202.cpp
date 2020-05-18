#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
#include <cstring>
using namespace std;
​
set<string> st;
set<string> fin;
int n, m;
int vis[4][4];
int sum = 0, ccnt = 0;
int di[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
int dj[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
char board[30][4][4];
string len;
int score(string str) {
    int ans = str.size();
    if (ans <= 2) {
        return 0;
    }
    else if (ans <= 4) {
        return 1;
    }
    else if (ans <= 5) {
        return 2;
    }
    else if (ans <= 6) return 3;
    else if (ans <= 7) return 5;
    else if (ans <= 8) return 11;
}
void ffind(int cnt, string str, int i, int j, int bid) {
    if (cnt > 8) return;
    set<string>::iterator iter1, iter2;
    iter1 = st.find(str);
    if (iter1 != st.end()) {
        iter2 = fin.find(str);
        if (iter2 == fin.end()) {
            if (len.size() < str.size())len = str;
            ccnt++;
            sum += score(str);
            fin.insert(str);
        }
    }
    for (int k = 0; k < 8; k++) {
        int dx = i + di[k];
        int dy = j + dj[k];
        if (dx < 0 || dx >= 4 || dy < 0 || dy >= 4 || vis[dx][dy])continue;
        vis[dx][dy] = 1;
        ffind(cnt + 1, str + board[bid][dx][dy], dx, dy, bid);
        vis[dx][dy] = 0;
    }
}
void solve(int bid) {
    ccnt = 0;
    sum = 0;
    fin.clear();
    len = "";
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            vis[i][j] = 1;
            char a = board[bid][i][j];
            string tmp;
            tmp += a;
            ffind(1, tmp,  i, j, bid);
            vis[i][j] = 0;
        }
    }
    for (auto& x : fin) {
        if (x.length() == len.length())
            len = min(len, x);
    }
    cout << sum << " " << len << " " << fin.size() << "\n";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        st.insert(str);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> board[i][j][k];
            }
        }
    }
​
    for (int i = 0; i < m; i++) {
        solve(i);
    }
}
