#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int expp[31];
bool flag;
map<int, int> ma;
struct trie {
    bool terminal, exist, valid;
    int cnt = 0;
    trie* node[2];
    trie() : terminal(false), exist(false), valid(false) {
        memset(node, 0, sizeof(node));
    }
    ~trie() {
        for (int i = 0; i < 2; i++)delete node[i];
    }
    void add(int val, int pow) {
        if (pow <= -1) return;
        if (val >= expp[pow]) {
​
            if (node[1] == NULL) {
                node[1] = new trie();
                cnt++;
            }
            node[1]->add(val - expp[pow], pow - 1);
        }
        else {
​
            if (node[0] == NULL) {
                node[0] = new trie();
                cnt++;
            }
            node[0]->add(val, pow - 1);
        }
    }
    int query(int val, int pow) {
        if (pow <= -1) return 0;
        if (val >= expp[pow]) {
            if (node[0] != NULL) return node[0]->query(val - expp[pow], pow - 1);
            else return expp[pow] + node[1]->query(val - expp[pow], pow - 1);
        }
        else {
            if (node[1] != NULL) return expp[pow] + node[1]->query(val, pow - 1);
            else return node[0]->query(val, pow - 1);
        }
    }
    void erase(int val, int pow) {
        if (pow == 0) {
            node[val] = NULL;
            cnt--;
            if (cnt >= 1) flag = true;
            return;
        }
        if (val >= expp[pow]) {
            node[1]->erase(val - expp[pow], pow - 1);
        }
        else {
            node[0]->erase(val, pow - 1);
        }
        if (flag) return;
        else {
            if (val >= expp[pow]) {
                node[1] = NULL;
                cnt--;
                if (cnt >= 1) flag = true;
                return;
            }
            else {
                node[0] = NULL;
                cnt--;
                if (cnt >= 1) flag = true;
                return;
            }
        }
    }
};
int n;
int a;
int op;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    trie* root = new trie();
    cin >> n;
    int mul = 1;
    for (int i = 0; i < 31; i++) {
        expp[i] = mul;
        mul *= 2;
    }
    root->add(0, 30);
    while (n--) {
        cin >> op;
        if (op == 1) {
            cin >> a;
            ma[a]++;
            root->add(a, 30);
        }   
        else if (op == 2) {
            cin >> a;
            if (--ma[a] <= 0) {
                flag = false;
                root->erase(a, 30);
            }
        }
        else {
            cin >> a;
            int temp = root->query(a, 30);
            int ans = temp ^ a;
            cout << ans << "\n";
        }
    }
}
