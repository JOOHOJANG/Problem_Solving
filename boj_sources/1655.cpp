#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
​
priority_queue<int, vector<int>, greater<int>> mi;
priority_queue<int, vector<int>, less<int>> ma;
int n;
int a;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (ma.empty()) ma.push(a);
        else if (ma.size() == mi.size()) ma.push(a);
        else mi.push(a);
        if (!ma.empty() && !mi.empty() && !(mi.top() >= ma.top())) {
            int a= mi.top();mi.pop();
            int b = ma.top(); ma.pop();
            ma.push(a);
            mi.push(b);
        }
        cout << ma.top() << "\n";
    }
}
​
