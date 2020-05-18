#include <stdio.h>
​
int main() {
    int a;
    scanf("%d", &a);
    for (int i = 1; i <= a; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= a; j++)
                printf("* ");
        }
        else
            for (int j = 1; j <= a; j++)
                printf(" *");
        printf("\n");
    }
}
