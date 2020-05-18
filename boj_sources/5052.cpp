#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
​
string str;
int n;
int t;
bool compare(string a, string b) {
    return a.size() < b.size();
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        set<string>s;
        vector<string> v;
        int mmin = 1e9;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> str;
            v.push_back(str);
            s.insert(str);
            mmin = min((int)str.size(), mmin);
        }
        sort(v.begin(), v.end(), compare);
        int st = v[0].size();
        for (int i = 1; i < v.size(); i++) {
            if (v[i].size() != st) {
                st = i;
                break;
            }
        }
        set<string>::iterator iter;
        bool flag = false;
        for (int i = st; i < v.size(); i++) {
            for (int j = mmin; j < v[i].size(); j++) {
                iter = s.find(v[i].substr(0, j));
                if (iter != s.end()) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }
}
