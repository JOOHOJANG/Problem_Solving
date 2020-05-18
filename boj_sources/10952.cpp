#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
​
int main() {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if (!a && !b) break;
        cout << a + b << "\n";
    }
}
