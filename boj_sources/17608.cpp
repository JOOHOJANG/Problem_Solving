#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
​
int n;
vector<int> v;
int cnt;
int st;
​
int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    st = v[v.size() - 1];
    cnt++;
    for(int i = v.size() - 2; i >= 0; i--) {
        if (v[i] > st) st = v[i], cnt++;
    }
    cout << cnt;
}
