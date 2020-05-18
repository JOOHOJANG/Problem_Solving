#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n, i, j;
    int sum = 0;
    scanf("%d", &n);
    vector<pair<int, string>>word(n);
    for (i = 0; i < n; i++) {
        cin >> word[i].second;
        word[i].first = word[i].second.size();
    }
    sort(word.begin(), word.end());
    for (i = 0; i < n - 1; i++) {
        if (word[i].second == word[i + 1].second) {
            word.erase(word.begin() + i);
            i--;
            n--;
        }
    }
    for (i = 0; i < n; i++) {
        cout << word[i].second << "\n"; 
    }
}
