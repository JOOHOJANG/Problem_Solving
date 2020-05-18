#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
​
int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        cout << a + b << "\n";
    }
}
