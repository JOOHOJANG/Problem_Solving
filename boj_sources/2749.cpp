#include <iostream>
#include <vector>
using namespace std;
long long n;
long long arr[1500050];
​
void fibo() {
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 0; i < 1500020; i++) {
        arr[i + 2] = (arr[i + 1] + arr[i])%1000000;
    }
}
int main() {
    cin >> n;
    fibo();
    cout << arr[n % 1500000];
}
