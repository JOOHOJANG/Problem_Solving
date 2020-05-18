#include <stdio.h>
​
int main() {
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
​
​
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < (n / 2); j++) {
            if ((r % 2 == 0 && c % 2 == 0) || (r % 2 != 0 && c % 2 != 0)) {
                if (i % 2 != 0) printf(".v");
                else printf("v.");
            }
            else {
                if (i % 2 == 0) printf(".v");
                else printf("v.");
            }
        }
        if (n % 2 != 0) {
            if ((r % 2 == 0 && c % 2 == 0) || (r % 2 != 0 && c % 2 != 0)) {
                if (i % 2 != 0) printf(".");
                else printf("v");
            }
            else {
                if (i % 2 == 0) printf(".");
                else printf("v");
            }
        }
        printf("\n");
​
    }
}
​
