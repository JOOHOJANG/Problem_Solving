#include <iostream>
#include <algorithm>
#include <vector>
​
using namespace std;
int n, m;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> m >> n;
    vector<int> v(2 * m - 1, 1);
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = a; i < a + b; i++) v[i] += 1;
        for (int i = a + b; i < a + b + c; i++) v[i] += 2;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0) cout << v[m - i - 1] << " ";
            else cout << v[m + j - 1] << " ";
        }
        cout << "\n";
    }
}
