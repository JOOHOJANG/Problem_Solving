#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v;
int arr[21];
int main() {
    cin >> n;
    v.resize(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 1) cnt++;
        arr[v[i]]++;
    }
    if (cnt >= 2) {
        cout << "A";
    }
    else {
        for (int i = 20; i >= 2; i--) {
            int val = arr[i] / 2;
            arr[i] = 0;
            arr[i - 1] += val;
        }
        if (arr[1] >= 2) cout << "A";
        else cout << "B";
    }
}
