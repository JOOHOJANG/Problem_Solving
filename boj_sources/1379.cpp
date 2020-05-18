#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
​
typedef struct aa {
    int idx;
    int st;
    int fi;
    int room;
    int art;
}aa;
struct lat {
    int time;
    int idx;
};
struct compare {
    bool operator()(lat a, lat b) { return a.time > b.time; }
};
bool compare2(aa a, aa b) { 
    if (a.st == b.st) return a.fi < b.fi;
    return a.st < b.st;
}
bool compare3(aa a, aa b) { return a.idx < b.idx; }
aa arr[100001];
int last[100001];
int depth=1;
int n;
priority_queue<lat, vector<lat>, compare> p;
void check(int st, int fi, int i) {
    lat tmp = p.top();
    if (st >= tmp.time) {
        p.pop();
        last[tmp.idx] = fi, tmp.time = fi;
        arr[i].room = tmp.idx;
        p.push(tmp);
    }
    else {
        lat temp;
        depth++;
        temp.time = fi, temp.idx = depth;
        arr[i].room = depth;
        last[depth] = fi;
        p.push(temp);
    }
}
​
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].idx >> arr[i].st >> arr[i].fi, arr[i].art = i;
    lat latest;
    latest.time = 0, latest.idx = 1;
    p.push(latest);
    sort(arr+1, arr + n+1, compare2);
​
    for (int i = 1; i <= n; i++) {
        check(arr[i].st, arr[i].fi, i);
    }
    cout << depth<<"\n";
    sort(arr + 1, arr + n + 1, compare3);
    for (int i = 1; i <= n; i++) cout << arr[i].room << "\n";
}
