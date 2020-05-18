#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
​
int a, n;
struct st {
    int id;
    int cnt;
    int time;
};
st arr[20];
int x;
int esp;
bool compare1(st a, st b) {
    if (a.cnt == b.cnt) return a.time < b.time;
    return a.cnt < b.cnt;
}
bool compare2(st a, st b) {
    return a.id < b.id;
}
int main() {
    cin >> a >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        bool find = false;
        for (int i = 0; i < a; i++) {
            if (x == arr[i].id) {
                arr[i].cnt++;
                find = true;
            }
        }
        if (find)continue;
        if (esp < a) {
            arr[esp].id = x;
            arr[esp].cnt = 1;
            arr[esp].time = i;
            esp++;
        }
        else {
            sort(arr, arr + a, compare1);
            arr[0].id = x;
            arr[0].cnt = 1;
            arr[0].time = i;
        }
    }
    sort(arr, arr + a, compare2);
    for (int i = 0; i < a; i++) {
        cout << arr[i].id << " ";
    }
}
