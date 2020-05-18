#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a, b;
int cnt;
void solve(long long num) {
    if (num > b) return;
    if (a <= num && num <= b) cnt++;
    solve(num * 10 + 4);
    solve(num * 10 + 7);
​
}
​
int main() {
    cin >> a >> b;
    
    solve(4);
    solve(7);
    cout << cnt;
}
