#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int ans;
int n, m, t;
char arr[22];
struct trie {
    bool terminal, valid;
    trie* node[128];
    trie() : valid(false), terminal(false) {
        memset(node, 0, sizeof(node));
    }
    ~trie() {
        for (int i = 0; i < 128; i++)delete node[i];
    }
    void add(const char* s, bool flag) {
        if (*s == 0) {
            terminal = flag;
            valid = flag;
        }
        else {
            int pos = *s;
            if (!node[pos]) node[pos] = new trie();
            terminal = flag;
            node[pos]->add(s + 1, flag);
        }
    }
    void dfs() {
        if (terminal) {
            ans++;
            return;
        }
        else if (valid) ans++;
        for (int i = 0; i < 128; i++) {
            if (node[i])node[i]->dfs();
        }
    }
};
​
​
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> t;
    while (t--) {
        trie* root = new trie();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr;
            root->add(arr, true);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> arr;
            root->add(arr, false);
        }
        ans = 0;
        root->dfs();
        cout << ans<<"\n";
        delete root;
    }
}
