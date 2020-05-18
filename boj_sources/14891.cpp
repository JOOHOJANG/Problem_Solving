#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
string str[5];
int n, a, b;
vector<pair<int, int>>v;
int arr[5];
int main() {
    cin >> str[1] >> str[2] >> str[3] >> str[4];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }
    for (int i = 0; i < n; i++) {
        memset(arr, 0, sizeof(arr));
        int st = v[i].first;
        int dir = v[i].second;
        arr[st] = dir;
        for (int j = st+1; j <= 4; j++) {
            string tmp = str[j-1];
            int dir = arr[j - 1];
            arr[j] = (str[j][6] == tmp[2]) ? 0 : dir * (-1);
        }
        for (int j = st-1; j >=1 ; j--) {
            string tmp = str[j + 1];
            int dir = arr[j + 1];
            if (dir == 0) continue;
            arr[j] = (str[j][2] == tmp[6]) ? 0 : dir * (-1);
        }
        for (int j = 1; j <= 4; j++) {
            if (arr[j] == 1) {
                char tmp = str[j][7];   
                for (int k = 7; k >= 1; k--) str[j][k] = str[j][k-1];
                str[j][0] = tmp;
            }
            else if (arr[j] == -1) {
                char tmp = str[j][0];
                for (int k = 0; k <= 6; k++) str[j][k] = str[j][k + 1];
                str[j][7] = tmp;
            }
        }
    }
    int ans = 0;
    if (str[1][0] == '1') ans += 1;
    if (str[2][0] == '1') ans += 2;
    if (str[3][0] == '1') ans += 4;
    if (str[4][0] == '1') ans += 8;
    cout << ans;
}
