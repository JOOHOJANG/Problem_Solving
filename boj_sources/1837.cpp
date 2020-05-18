#include <iostream>
#include <vector>
#include <string>
using namespace std;
string str;
int n;
vector<int> v;
bool p[10000001];
void makeprime() {
    p[2] = true;
    v.emplace_back(2);
    for (int i = 3; i <= 10000000; i += 2) {
        p[i] = true;
    }
    for (int i = 3; i <= 10000000; i += 2) {
        if (p[i]) {
            v.emplace_back(i);
            int v = i + i;
            while (v <= 10000000) {
                p[v] = false;
                v += i;
            }
        }
    }
}
long long int mod(int n) {
    long long int ret = 0;
    for (int i = 0; i < str.size(); i++)ret = (ret * 10 + (str[i] - '0')) % n;
    return ret;
}
int main() {
    makeprime();
    cin >> str >> n;
    int i = 0;
    bool flag = false;
    while (v[i] < n) {
        if (!mod(v[i])) {
            flag = true;
            break;
        }
        i++;
    }
    if (flag) {
        cout << "BAD " << v[i];
    }
    else cout << "GOOD";
}
