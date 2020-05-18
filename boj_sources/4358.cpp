#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
using namespace std;
map<string, int> m;
set<string> se;
vector<string> v;
string s;
​
struct t {
    string str;
    double rat;
};
vector<t> ans;
int sum;
int cnt = 0;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    while (1) {
        getline(cin, s);
        if (s.size() == 0) break;
        m[s]++;
        se.insert(s);
        cnt++;
    }
    set<string>::iterator iter;
    for (iter = se.begin(); iter != se.end(); iter++) {
        v.push_back(*iter);
    }
    vector<int>a(v.size());
    for (int i = 0; i < v.size(); i++) {
        a[i] = m[v[i]];
        sum += a[i];
    }
    ans.resize(v.size());
    for (int i = 0; i < v.size(); i++) {
        ans[i].str = v[i];
        ans[i].rat = (double)a[i]*100 / (double)sum;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << fixed;
        cout.precision(4);
        cout << ans[i].str << " " << ans[i].rat << "\n";
    }
}
