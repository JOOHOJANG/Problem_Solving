#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
using lint = long long int;
​
lint a;
​
int main() {
    while (scanf("%lld", &a)!=EOF) {
        lint cnt = 1;
        lint sum = 0;
        lint i = 1;
        while(1) {
            if (i % a == 0) break;
            i = (i * 10) % a + 1;
            cnt++;
        }
        cout << cnt<<"\n";
    }
}
