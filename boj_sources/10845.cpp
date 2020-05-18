#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
​
int n;
string str;
int a;
queue<int> st;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "push") {
            cin >> a;
            st.push(a);
        }
        if (str == "pop") {
            if (!st.empty()) {
                a = st.front();
                st.pop();
                cout << a << "\n";
            }
            else cout << -1 << "\n";
        }
        if (str == "size") {
            cout << st.size() << "\n";
        }
        if (str == "empty") {
            if (!st.empty()) {
                cout << 0 << "\n";
            }
            else cout << 1 << "\n";
        }
        if (str == "front") {
            if (!st.empty()) {
                a = st.front();
                cout << a << "\n";
            }
            else cout << -1 << "\n";
        }
        if (str == "back") {
            if (!st.empty()) {
                a = st.back();
                cout << a << "\n";
            }
            else cout << -1 << "\n";
        }
    }
}
