#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long a, b;
void go(long long a, long long b, long long turn) {
    if (a < b) swap(a, b);
    if (turn == 1) {
        if (a > 2 * b) {
            cout << "lose";
            return;
        }
        else if (a % b == 0) {
            cout << "lose";
            return;
        }
        else if (a > b&& a < 2 * b) {
            go(a - b, b, 0);
        }
    }
    else if (turn == 0) {
        if (a > 2 * b) {
            cout << "win";
            return;
        }
        else if (a % b == 0) {
            cout << "win";
            return;
        }
        else if (a > b&& a < 2 * b) {
            go(a - b, b, 1);
        }
    }
}
int main() {
    cin >> a >> b;
    if (a < b) swap(a, b);
    if (a > 2 * b) cout << "win";
    else if (a % b == 0) cout << "win";
    else if (a > b&& a < 2 * b) {
        go(a - b, b, 1);
    }
}
