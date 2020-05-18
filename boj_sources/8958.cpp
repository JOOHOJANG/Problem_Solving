#include <iostream>
#include <string>
using namespace std;
​
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int cnt = 1, ans = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'O') {
                ans += cnt;
                cnt++;
            }
            else {
                cnt = 1;
            }
        }
        cout << ans << "\n";
    }
}
