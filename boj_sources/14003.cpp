#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arr;
int n;
int buffer[1'000'001];
int previous_idx_of[1'000'001], inserted_pos[1'000'001];
​
void print_all(int idx) {
    if (!idx) return;
    print_all(previous_idx_of[idx]);
    printf("%d ", buffer[idx]);
}
​
int main() {
    int val, idx, lastidx = -1;
    scanf("%d", &n);
    arr.push_back(-1'000'000'001);
    for (int i = 1; i <= n; i++)
        scanf("%d", buffer + i);
    for (int i = 1; i <= n; i++) {
        if (arr.back() < buffer[i]) {
            idx = arr.size();
            arr.push_back(buffer[i]);
            lastidx = max(lastidx, i);
        }
        else {
            idx = lower_bound(arr.begin(), arr.end(), buffer[i]) - arr.begin();
            arr[idx] = buffer[i];
        }
        inserted_pos[idx] = i;
        previous_idx_of[i] = inserted_pos[idx - 1];
​
    }
    printf("%d\n", arr.size() - 1);
    print_all(lastidx);
​
    printf("\n");
​
    return 0;
}
