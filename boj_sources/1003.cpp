#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
using ll = long long;
​
int c; 
int n;
int fibo[41];
​
int main() {
    cin >> c;
    for (int z = 0; z < c; z++) {
        memset(fibo, 0, sizeof(fibo));
        cin >> n;
        if (n == 0) {
            cout << "1" << " " << "0" << "\n";
            continue;
        }
        if (n == 1) {
            cout << "0" << " " << "1" << "\n";
            continue;
        }
        fibo[n]++;
        for (int i = n; i >= 2; i--) {
            while (fibo[i] > 0) fibo[i - 1]++, fibo[i - 2]++, fibo[i]--;
        }
        cout << fibo[0] << " " << fibo[1] << "\n";
    }
}
