#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int parent[1000001];
int find(int a) {
    if (a == parent[a]) return a;
    else {
        int p = find(parent[a]);
        parent[a] = p;
        return p;
    }
}
​
void merge(int a, int b) {
​
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
​
    for (int i = 1; i <= 1000000; i++)parent[i] = i;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            int a, b;
            cin >> a >> b;
            merge(a, b);
        }
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            if (find(a) != find(b))cout << "NO" << "\n";
            else cout <<"YES" << "\n";
        }
    }
}
