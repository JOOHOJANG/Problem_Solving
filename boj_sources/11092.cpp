#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
vector<int> v;
int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    int sum = 0;
    while (v.size()) {
        if (v.size() == 1) {
            sum += v[0];
            break;
        }
        if (v.size() > 3) {
            int val1 = 0, val2 = 0;
            val1 = v[v.size() - 1] + v[v.size() - 2] + 2 * v[0];
            val2 = v[1] + v[0] + v[1] + v[v.size() - 1];
            int tmp= val1 > val2 ? val2 : val1;
            sum += tmp;
            v.pop_back(); v.pop_back();
        }
        else if (v.size() == 3) {
            sum += v[2] + v[0] + v[1];
            break;
        }
        else if (v.size() == 2) {
            sum += v[1];
            break;
        }
    }
    cout << sum;
}
