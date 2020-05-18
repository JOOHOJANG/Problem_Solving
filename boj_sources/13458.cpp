#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
​
int n, a, b, c;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    long long cnt = 0;
    cin >> b >> c;
    for (int i = 0; i < v.size(); i++) {
        if (b >= v[i]) {
            cnt++;
            continue;
        }
        else {
            cnt++;
            v[i] -= b;
            if(v[i]%c !=0){
            cnt += ((v[i] / c)+1);
            }
            else {
                cnt += (v[i] / c);
            }
        }
    }
    cout << cnt;
}
