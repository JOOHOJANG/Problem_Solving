#include <stdio.h>
​
int stack[100001];
int top = -1;
​
int main() {
    int t;
    int n;
    int sum = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        if (n == 0)
            stack[top] = 0, top--;
        else
            top++, stack[top] = n;
    }
    if (top == -1) {
        printf("0");
        return 0;
    }
    for (int i = 0; i <= top; i++) {
        sum += stack[i];
    }
    printf("%d", sum);
    return 0;
}
