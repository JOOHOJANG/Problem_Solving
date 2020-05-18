#include <iostream>
#include <queue>
using namespace std;
​
int main() {
    queue<int>q;
    int i, n, k;
    cin >> n >> k;
    for (i = 1; i <= n; i++) q.push(i);
    cout << "<";
    while (q.size() > 0) {
        if (q.size() == 1) {
            cout << q.front() << ">";
            q.pop();
            break;
        }
        for (i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << "\n";
    return 0;
}
