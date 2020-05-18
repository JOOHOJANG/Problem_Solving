#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<int> v;
​
int main() {
    cin >> n >> k;
    v.resize(n+1);
    for (int i = 2; i <= n; i++)v[i] = i;
    int cnt=0;
    int val = -1;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (v[j] % i == 0) {
                cnt++;
                if (cnt == k) {
                    cout << v[j];
                    return 0;
                }
                v[j] = val;
            }
        }
    }
​
}
