#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
​
int n, k, result;
string word[50];
int vis[26];
​
void check(int idx, int cnt) {
    if (cnt == k) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < word[i].length(); j++) {
                if (!vis[word[i][j] - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) temp++;
        }
        result = max(result, temp);
        return;
    }
​
    for (int i = idx; i < 26; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            check(i, cnt + 1 );
            vis[i] = 0;
        }
    }
}
int main() {
    cin >> n >> k;
    if (k < 5) {
        cout << 0;
        return 0;
    }
    if (k == 26) {
        cout << n;
        return 0;
    }
    k -= 5;
    for (int i = 0; i < n; i++) {
​
        cin >> word[i];
        word[i] = word[i].substr(4, word[i].length());
        for (int j = 0; j < 4; j++)word[i].pop_back();
​
    }
    vis['a' - 'a'] = 1; vis['n' - 'a'] = 1; vis['t' - 'a'] = 1; vis['i' - 'a'] = 1; vis['c' - 'a'] = 1;
    check(0, 0);
    cout << result;
}
