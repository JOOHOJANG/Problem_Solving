#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
​
​
string str;
vector<string> ans;
int main() {
    while (1) {
        hey:
        stack<char> st;
        st.push('+');
        bool flag = false;
        getline(cin, str);
        if (str.size() == 1) {
            if (str[0] == '.') break;
        }
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '[' || str[i] == '(') st.push(str[i]);
            else if (str[i] == ']' ) {
                if (st.top() == '[') {
                    st.pop();
                }
                else {
                    ans.push_back("no");
                    goto hey;
                }
            }
            else if (str[i] == ')') {
                if (st.top() == '(') {
                    st.pop();
                }
                else {
                    ans.push_back("no");
                    goto hey;
                }
            }
        }
        if (st.size() == 1) ans.push_back("yes");
        else ans.push_back("no");
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}
