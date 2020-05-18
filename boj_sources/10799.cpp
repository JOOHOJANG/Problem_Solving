#include <stdio.h>
​
​
​
char stack[100001];
int num[100001];
int top = -1;
​
​
​
void push(char c) {
    top++;
    stack[top] = c;
}
char pop() {
​
    int temp = stack[top];
    top--;
    return temp;
​
}
​
​
​
char pick() {
    return stack[top];
}
int main() {
    int index = 0;
    int sum = 0;
    char str[100001] = { 0, };
​
    scanf("%s", str);
    int i, j;
​
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            push('(');
            num[++index] = 1;
        }
        else if (str[i] == ')') {
            if (pick() == '(' && str[i - 1] == '(') {
                num[index] = 0;
                index--;
                for (j = 1; j <= index; j++) {
                    num[j]++;
                }
            }
            else {
                sum += num[index];
                index--;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
