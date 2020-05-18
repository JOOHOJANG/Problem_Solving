#include <iostream>
#include <stack>
#include<vector>
​
using namespace std;
vector<int> v;
stack<int> st;
int n;
vector<char> ans;
int main() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)v[i] = i;
    vector<int> arr;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    st.push(0);
    int last = -1;
    int cnt = 1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > last) {
            int iter = 0;
            while (st.top() != arr[i]) {
                st.push(v[cnt++]);
                ans.push_back('+');
                iter++;
                if (iter > n) {
                    cout << "NO";
                    return 0;
                }
            }
            last = arr[i];
            ans.push_back('-');
            st.pop();
        }
        else if (arr[i] < last) {
            if (st.top() != arr[i]) {
                cout << "NO";
                return 0;
            }
            else {
                st.pop();
                ans.push_back('-');
                last = arr[i];
            }
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}
