#include <iostream>
using namespace std;
​
int arr[10001];
int n, m;
int cnt;
int sum;
​
int main() {
​
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> arr[i];
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == m) {
            sum = 0;
            cnt++;
            continue;
        }
        if (sum > m) {
            sum = 0;
            continue;
        }
        for (int j = i+1; j < n; j++) {
            sum += arr[j];
            if (sum == m) {
                sum = 0;
                cnt++;
                break;
            }
            if (sum > m) {
                sum = 0;
                break;
            }
        }
        sum = 0;
    }
    cout << cnt;
}
