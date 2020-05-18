#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
​
​
char a[50];
int main() {
    int i, n, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        char stack[50];
        int top = -1;
        int flag = 0;
        scanf("%s", a);
        int len = strlen(a);
        for (j = 0; j <len; j++) {
            if (a[j] == '(') top++, stack[top] = a[j];
            else {
                if (top==-1) {
                    flag = 1;
                    break;
                }
                else stack[top] = ' ', top--;
            }
        }
        if (flag) {
            printf("NO\n");
            continue;
        }
        if (top!=-1) printf("NO\n");
        else printf("YES\n");
    }
}
