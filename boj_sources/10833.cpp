#include <iostream>
#include <algorithm>
using namespace std;
​
int n;
int s, a;
​
int cnt;
​
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> a;
        cnt += a % s;
    }
    cout << cnt;
}
