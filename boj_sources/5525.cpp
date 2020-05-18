#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
​
int main() {
    int n;
    int s;
    string str;
​
    cin >> n >> s >> str;
​
    int i = 0;
    int cnt = 0;
    int res = 0;
    for (int i = 1; i < s - 1; i++) {
        if (str[i] == 'O' && str[i - 1] == 'I' && str[i + 1] == 'I') {
            cnt++;
            if (cnt == n) {
                res++;
                cnt--;
            }
            i++;
        }
        else {
            cnt = 0;
        }
    }
    cout << res;
}
