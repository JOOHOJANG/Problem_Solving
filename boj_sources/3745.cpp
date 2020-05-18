#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int t;
int main() {
    while (scanf("%d", &t) != EOF) {
        vector<int> v;
        vector<int>ans(t, 10000000);
        int a;
        v.resize(t);
        for (int i = 0; i < t; i++) { 
            cin >> v[i]; 
            int ret = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
            ans[ret] = v[i];
        }
        int cnt = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 10000000)break;
            cnt++;
        }
        cout << cnt << "\n";
    }
}
