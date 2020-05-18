#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
​
vector<int> v;
bool p[1000001];
void makeprime() {
    p[2] = true;
    for (int i = 3; i <= 1000000; i += 2) {
        p[i] = true;
    }
    for (int i = 3; i <= 1000000; i += 2) {
        if (p[i]) {
            v.emplace_back(i);
            int v = i + i;
            while (v <= 1000000) {
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
    while (1) {
        cin >> a;
        if (!a) break;
        bool flag = false;
        for (int i = 3; i <= a; i++) {
            if (p[i]) {
                int o = a - i;
                if (p[o]) {
                    printf("%d = %d + %d\n", a, i, o);
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) printf("Goldbach's conjecture is wrong.\n");
    }
}
