#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <string>
using namespace std;
vector<pair<int, string>>N;
int n;
bool compare(pair <int, string>a, pair<int, string>b) {
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
        return false;
    else return false;
}
int main() {
    int i;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    N.resize(n);
    for (i = 0; i < n; i++) cin >> N[i].first >> N[i].second;
    stable_sort(N.begin(), N.end(), compare);
    for (i = 0; i < n; i++) cout << N[i].first << " " << N[i].second << "\n";
}
