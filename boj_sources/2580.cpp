#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int arr[9][9];
int ch[10];
vector<pii>v;
​
bool check(int x, int y, int num) {
    
    for (int i = 0; i < 9; i++) {
        if (arr[x][i] == num) return false;
    }
    
    for (int i = 0; i < 9; i++) {
        if (arr[i][y] == num) return false;
    }
​
    int dx = (x / 3) * 3;
    int dy = (y / 3) * 3;
    for (int i = dx; i < dx + 3; i++) {
        for (int j = dy; j < dy + 3; j++) {
            if (arr[i][j] == num) return false;
        }
    }
    return true;
}
​
bool backtrack(int idx) {
    if (idx >= v.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        return true;
    }
    pii p = v[idx];
    int x = p.first;
    int y = p.second;
    bool succ = false;
    for (int i = 1; i <= 9; i++) {
        if (!check(x, y, i)) {
            continue;
        }
        arr[x][y] = i;
        if (backtrack(idx + 1)) {
            succ = true;
            break;
        }
    }
    arr[x][y] = 0;
    return succ;
​
}
​
int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (!arr[i][j]) v.push_back(make_pair(i, j));
        }
    }
    backtrack(0);
}
