#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
​
using lint = long long int;
using pii = pair<lint, lint>;
​
priority_queue<lint>pq;
lint n, m, k, x, y;
vector<pair<lint, lint>>v;
vector<lint> bag;
​
lint cnt, sum;
bool compare(pair<lint, lint> a, pair<lint, lint>b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}
​
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (lint i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for (lint i = 0; i < m; i++) {
        cin >> x;
        bag.push_back(x);
    }
    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());
    for (lint i = 0, j=0; i < m; i++) {
        while (j < n && v[j].first <= bag[i])
            pq.push(v[j++].second);
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }   
    
    cout << sum;
}
