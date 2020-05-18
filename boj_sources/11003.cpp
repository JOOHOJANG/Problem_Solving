#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
​
int min;
int n, l;
int arr[5000001];
int a;
deque<pair<int, int>> dq;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n>> l;
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        while (dq.size() && dq.front().second <= i-l) dq.pop_front();
        while (dq.size() && dq.back().first >=arr[i]) dq.pop_back();
        dq.push_back({ arr[i], i });
        cout << dq.front().first << " ";
    }
}
