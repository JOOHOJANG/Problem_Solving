#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int c1, c2;
​
​
​
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        int tt = i;
        while (tt % 2 == 0) {
            c1++;
            tt /= 2;
        }
        while (tt % 5 == 0) {
            c2++;
            tt /= 5;
        }
    }
    cout << min(c1, c2);
}
