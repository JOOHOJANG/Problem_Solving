#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
vector<int> v;
bool p[4000001];
void makeprime() {
    p[2] = true;
    for (int i = 3; i <= 4000000; i += 2) {
        p[i] = true;
    }
    v.emplace_back(2);
    for (int i = 3; i <= 4000000; i += 2) {
        if (p[i]) {
            v.emplace_back(i);
            int v = i + i;
            while (v <= 4000000) {
                p[v] = false;
                v += i;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
​
    makeprime();
    int a;
    cin >> a;
    int lo = 0, hi = 0;
    int sum = 0;
    int cnt = 0;
    while (lo < v.size() && hi < v.size()) {
        if (sum < a) sum += v[hi++];
        if (sum == a) {
            cnt++;
            sum += v[hi++];
        }
        if (sum > a) {
            sum -= v[lo++];
            if (lo > hi) hi = lo;
        }
    }
    cout << cnt;
}
