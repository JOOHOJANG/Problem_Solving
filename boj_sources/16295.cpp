#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
map<pii, int> ma;
struct compare {
    bool operator()(ppi a, ppi b) {
        return a.second > b.second;
    }
};
priority_queue<ppi, vector<ppi>, compare> pq;
​
int n, m;
vector<int> v1, v2;
bool flag;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
​
    cin >> n >> m;
    v1.resize(n), v2.resize(m);
    for (int i = 0; i < n; i++) cin>>v1[i];
    for (int i = 0; i < m; i++) cin>>v2[i];
    sort(v2.begin(), v2.end());
    
    for (int i = n - 1; i >= 1; i--) {
        int dist = v1[i] - v1[i - 1];
        int ii = i - 1;
        pq.push({ {ii, i}, dist });
    }
    for (int ii = 0; ii < v2.size(); ii++) {
    hello:
        if (pq.empty()) {
            flag = true;
            break;
        }
        
        int len = v2[ii];
        ppi aa = pq.top(); pq.pop();
        int i = aa.first.first, j = aa.first.second;
        int dist = aa.second;
        if (dist > len) {
            flag = true;
            break;
        }
        if (ma[{i, j}]) goto hello;
        ma[{i, j}]++;
        int newi = i - 1;
        int newj = j + 1;
        if (newi >= 0 && newj < n && newi<newj) {
            if(!ma[{i, newj}])pq.push({ {i, newj}, dist + v1[newj] - v1[j] });
            if(!ma[{newi, j}])pq.push({ { newi, j }, dist + v1[i] - v1[newi] });    
        }
        else if (newi >= 0) {
            if (!ma[{newi, j}])pq.push({ { newi, j }, dist + v1[i] - v1[newi] });
        }
        else if (newj < n) {
            if (!ma[{i, newj}])pq.push({ {i, newj}, dist + v1[newj] - v1[j] });
        }
    }
    if (flag) cout << "no";
    else cout << "yes";
}
