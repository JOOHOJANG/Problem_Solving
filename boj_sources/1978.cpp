#include <stdio.h>
​
int find(int n) {
    int i;
    if (n == 1) return 0; 
    if (n == 2) return 1;
    for (i = 2; i < n; i++) {
        if (n % i == 0) { 
            return 0;
        }
    }
    return 1;
}
​
int main() {
    int t; 
    int i;
    int num = 0;
    int x; 
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d ", &x);
        if (find(x)) {
            num++;
        }
    }
    printf("%d", num);
}
