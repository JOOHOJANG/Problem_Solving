#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
​
int h, w;
int k;
int n;
vector<pair<int, int>> v;
bool isPossible(int mid) {
    int cnt = 0;
    int square = 0;
    vector<int> visited;
    visited.resize(n);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        square++;
        int here_x = v[i].first;
        cnt++;
        for (int j = 0; j < n; j++) {
            int there_x = v[j].first, there_y = v[j].second;
            if (visited[j]) continue;
            if (here_x + mid > there_x && there_y <= mid) {
                visited[j] = true;
                cnt++;
            }
            else if (there_y > mid) return false;
        }
    }
    if (square > k || cnt != n) return false;
    else return true;
}
​
​
​
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
​
    cin >> h >> w >> k;
    cin >> n;
​
    v.resize(n);
​
    for (int i = 0; i < n; i++)
        cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end());
    int left = 1;
    int ans = 2100000000;
    int right = max(h, w);
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(mid)) {
            right = mid - 1;
            ans = min(mid, ans);
        }
        else
            left = mid + 1;
    }
    cout << ans;
}
