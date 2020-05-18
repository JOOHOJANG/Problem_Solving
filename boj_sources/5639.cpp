#include <iostream>
#include <vector>
​
using namespace std;
​
vector<int> arr;
​
void preToPost(int l, int r) {
    int ans = l; 
    int sub = l++; 
    while (arr[++sub] < arr[ans]); 
    if (l <= sub - 1)
        preToPost(l, sub - 1);
    if (sub <= r)
        preToPost(sub, r);
    cout << arr[ans] << '\n';
}
​
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int input;
    while (cin >> input) arr.push_back(input);
    arr.push_back(20000000);
    preToPost(0, arr.size() - 2);
    return 0;
}
​
