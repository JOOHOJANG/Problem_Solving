#include <iostream>
#include <algorithm>
using namespace std;
​
struct aa {
    int fi;
    int st;
};
aa arr[100001];
int n;
int total;
bool compare(aa a, aa b) {
    if (a.fi == b.fi) return a.st < b.st;
    return a.fi < b.fi;
}
​
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
​
    cin >> n;
    for (int i = 0; i < n; i++)cin >> arr[i].st >> arr[i].fi;
    sort(arr, arr + n, compare);
​
    int st = 0;
    for (int i = 1; i < n; i++) {
        if (st > arr[i].st) continue;
        else {
            total++;
            st = arr[i].fi;
        }
    }
    cout << total;
}
