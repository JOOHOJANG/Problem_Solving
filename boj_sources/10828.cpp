#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
​
int n;
string str;
int a;
stack<int> st;
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
                a = st.top();
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
        if (str == "top") {
            if (!st.empty()) {
                a = st.top();
                cout << a << "\n";
            }
            else cout << -1 << "\n";
        }
    }
}
