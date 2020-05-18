#include <iostream>
#include <vector>
using namespace std;
int N;
int arr[1001] = { 0, 2 };
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    for (int i = 2; i <= 1000; i++) {
        int n = 0;
        for (int j = 1; j <= i; j++) {
            if (gcd(i, j) == 1) n++;
        }
        arr[i] = arr[i - 1] + n;
    }
    cin >> N;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        cout << 2 * arr[x] - 1 << "\n";
    }
}
