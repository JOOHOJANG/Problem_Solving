#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2100000000
using namespace std;
​
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int>vv(n+1, MAX);
    vector<int>v(n+1);
​
    for (int i = 0; i < n; i++)cin >> v[i]; //입력받음
    int a;
    for (int i = 0; i < n; i++) {
        a = lower_bound(vv.begin(), vv.end(), v[i])-vv.begin();//들어갈 자리 찾기
        vv[a] = v[i]; //넣기
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (vv[i] == MAX)break;
        cnt++;
    }
    cout << cnt << "\n";
    /*for (int i = 0; i < cnt; i++) {
        cout << vv[i] << " ";
    }*/
}
