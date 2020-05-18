#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
​
int main() {
    int n;
    string str;
    cin >> n;
    for (int i = 1; i <= 9; i++) {
        cout << n << " * " << i << " " << "=" << " " << n * i << "\n";
    }
}
