#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool p[10000001];
vector<int> v;
void makeprime() {
    p[2] = true;
    for (int i = 3; i <= 10000000; i += 2) p[i] = true;
    v.push_back(2);
    for (int i = 3; i <= 10000000; i += 2) {
        if (p[i]) {
            p[i] = false;
            v.push_back(i);
            int v = i + i;
            while (v <= 1000000) {
                p[v] = false;
                v += i;
            }
        }
    }
}
int main() {
    makeprime();
    int n;
    cin >> n;
    int i = 0;
    while (i<v.size()) {
        while (n % v[i] == 0 && i<v.size()) {
            n /= v[i]; 
            cout << v[i] << "\n";
        }
        i++;
        if (p[n]) break;
    }
}
