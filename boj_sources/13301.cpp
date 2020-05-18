#include <iostream>
using namespace std;
​
long long ans;
int n;
int main() {
    cin >> n;
    long long int ans=0;
    long long int a = 1, b = 1;
    long long int fin=0;
    if (n ==1) {
        cout << 4;
        return 0;
    }
    if (n == 2) {
        cout << 6;
        return 0;
    }
    else {
        for (int i = 0; i < n-2; i++) {
            ans = a + b;
            fin = b;
            a = b;
            b = ans;
        }
        cout << 4*ans+2*fin;
    }
}
