#include <iostream>
using namespace std;
int t;
int arr[3];
int main() {
    cin >> t;
    if (t % 10 != 0) {
        printf("-1");
        return 0;
    }
    while (t >= 300) {
        t -= 300;
        arr[0]++;
    }
    while (t >= 60) {
        t -= 60;
        arr[1]++;
    }
    while (t >= 10) {
        t -= 10;
        arr[2]++;
    }
    printf("%d %d %d", arr[0], arr[1], arr[2]);
}
