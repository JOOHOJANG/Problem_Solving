#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int a, b;
int arr[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> a;
    arr[1] = a;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        arr[i] = arr[i - 1] + a;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        cout << arr[b] - arr[a - 1]<<"\n";
    }
}
