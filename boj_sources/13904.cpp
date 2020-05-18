#include <iostream>
#include <algorithm>
using namespace std;
​
struct aa {
    int dead;
    int profit;
};
aa arr[1001];
int parent[1001];
int n;
int total;
bool compare(aa a, aa b) {return a.profit > b.profit;}
​
int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
​
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    parent[x] = y;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
​
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].dead >> arr[i].profit;
    for (int i = 1; i <= 1001; i++)parent[i] = i;
    sort(arr+1, arr + n+1, compare);
    for (int i = 1; i <= n; i++) {
        int a = find(arr[i].dead);
        if (!a) continue;
        else {
            total += arr[i].profit;
            merge(a, a - 1);
        }
    }
    cout << total;
}
