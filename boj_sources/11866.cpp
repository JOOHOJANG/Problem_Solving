#include <iostream>
#include <queue>
#include <vector>
using namespace std;
​
int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    vector<int> ans;
    while (!q.empty()) {
        vector<int> tmp;
        for (int i = 0; i < k-1; i++) {
            int a = q.front();
            q.pop();
            q.push(a);
            tmp.push_back(a);
        }
        ans.push_back(q.front()); q.pop();
    }
    cout << "<";
    for (int i = 0; i < ans.size()-1; i++) cout << ans[i] <<", ";
    cout << ans[ans.size() - 1] << ">";
​
}
