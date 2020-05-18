#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <deque>
using namespace std;
​
deque<int> d;
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        d.push_back(i);
    }
    while (d.size() != 1) {
        d.pop_front();
        int a = d.front(); d.pop_front();
        d.push_back(a);
    }
    int ans = d.front();
    cout << ans;
}
