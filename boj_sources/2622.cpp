#include <iostream>
#include <algorithm>
using namespace std;
​
int n;
int cnt;
int main() {
    cin >> n;
    if (n < 3) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            int k = n - (i + j);
            if (k < j) break;
            if (i + j > k)cnt++;
        }
    }
    cout << cnt;
}
