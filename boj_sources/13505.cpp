#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
#include <string>
using namespace std;
int expp[31];
struct trie {
    bool terminal, valid, exist;
    trie* node[2];
    trie() : terminal(false), valid(false), exist(false) {
        memset(node, 0, sizeof(node));
    }
    ~trie() {
        for (int i = 0; i < 2; i++)delete node[i];
    }
    void add(int val, int pow) {
        if (pow <= -1) return;
        if (val >= expp[pow]) {
            if (node[1] == NULL) node[1] = new trie();
            node[1]->add(val - expp[pow], pow - 1);
        }
        else {
            if (node[0] == NULL) node[0] = new trie();
            node[0]->add(val, pow - 1);
        }
    }
​
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
};
int n;
int arr[100001];
int ans;
int main() {
    trie* root = new trie();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int mul = 1;
    for (int i = 0; i < 31; i++) {
        expp[i] = mul;
        mul *= 2;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        root->add(arr[i], 30);
    }
    for (int i = 0; i < n; i++) {
        int temp = root->query(arr[i], 30);
        ans = max(ans, temp ^ arr[i]);
    }
    cout << ans;
}
