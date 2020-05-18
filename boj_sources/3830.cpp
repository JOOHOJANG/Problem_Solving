#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
​
long long par[100001];
long long diff[100001];
​
long long find(long long a) {
    if (a == par[a])return a;
    else {
        long long tmp = par[a];
        par[a] = find(par[a]);
        diff[a] += diff[tmp];
        return par[a];
    }
}
void merge(long long a, long long b, long long k) {
    long long aa = find(a);
    long long bb = find(b);
    if (aa != bb) {
        diff[bb] = k - diff[b] + diff[a];
        par[bb] = aa;
    }
}
void set() {
    for (long long i = 0; i < 100001; i++) {
        par[i] = i;
        diff[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (1) {
        set();
        long long z, x;
        cin >> z >> x;
        if (!z && !x) break;
        for (long long i = 0; i < x; i++) {
            char op;
            cin >> op;
            if (op == '!') {
                long long a, b, c;
                cin >> a >> b >> c;
                merge(a, b, c);
            }
            if (op == '?') {
                long long a, b;
                cin >> a >> b;
                long long aa = find(a);
                long long bb = find(b);
                if (aa == bb) {
                    cout << diff[b] - diff[a] << "\n";
                }
                else cout << "UNKNOWN\n";
            }
        }
    }
}
