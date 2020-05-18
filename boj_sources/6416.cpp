#include <iostream>
#include <unordered_set>
using namespace std;
​
unordered_set<int> node;
int u, v;
int line;
int cnt = 1;
int main() {
    while (1) {
        cin >> u >> v;
        if (u == -1 && v == -1) {
            break;
        }
        if (u == 0 && v == 0) {
            if (line == 0 || node.size() == line + 1) {
                printf("Case %d is a tree.\n", cnt);
                node.clear();
                line = 0;
                cnt++;
                continue;
            }
            else {
                printf("Case %d is not a tree.\n", cnt);
                node.clear();
                line = 0;
                cnt++;
                continue;
            }
        }
        node.insert(u);
        node.insert(v);
        line++;
    }
}
