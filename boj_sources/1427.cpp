#include <cstdio>
#include <algorithm>
#include <iostream>
char a[10];
bool compare(char a, char b) { return a > b; }
int main() {
    int i = 0;
    while (1) {
        scanf("%c", &a[i]);
        if (a[i] == '\n') break;
        i++;
    }
    std::sort(a, a + i, compare);
    printf("%s", a);
}
