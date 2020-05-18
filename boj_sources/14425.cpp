#include <iostream>
#include <string>
#include <set>
using namespace std;
​
set<string> s;
int n, m;
int cnt;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        s.insert(str);
    }
    set<string>::iterator iter;
    for (int i = 0; i < m; i++) {
        cin >> str;
        iter = s.find(str);
        if (iter != s.end()) cnt++;
    }
    cout << cnt;
}
