#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
​
int n, m;
char arr[51][51];
int ans = 1002000;
string b[8] = {
    {"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"}
};
​
string w[8] = {
    {"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"}
};
​
void go(int x, int y) {
    int c1 = 0, c2 = 0;
    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            if (arr[i][j] != b[i - x][j - y])c1++;
        }
    }
    
    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            if (arr[i][j] !=w[i - x][j - y])c2++;
        }
    }
    
    ans = min(ans, min(c1, c2));
​
}
​
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
​
    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            go(i, j);
        }
    }
​
    cout << ans;
}
