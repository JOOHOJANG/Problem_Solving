#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<string> v;
int vis[10];
int cnt;
map<string, int> ma;
int n, k;
string str;
void go(int a, string str) {
    if (a == k) {
        if (!ma[str]) {
            cnt++;
            ma[str]++;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (!vis[i]) {
            vis[i] = 1;
            string tmp = str;
            str += v[i];
            go(a + 1, str);
            str = tmp;
            vis[i] = false;
        }
    }
}
int main() {
​
    cin >> n >> k;
    string st;
    for (int i = 0; i < n; i++)cin >> st, v.push_back(st);
​
    go(0, "");
    cout << cnt;
}
