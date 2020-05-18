#include <stdio.h>
#include <string.h>
​
char a[50];
char b[50];
int main() {
    int i, j;
    scanf("%s %s", a, b);
    int lena = strlen(a);
    int lenb = strlen(b);
    int min = 51;
    if(lena<lenb){
        for (i = 0; i <= lenb - lena; i++) {
            int cnt = 0;
            for (j = 0; j < lena; j++) {
                if (a[j] != b[j + i]) cnt++;
            }
            if (cnt < min) min = cnt;
        }
    }
    else {
        int cnt = 0;
        for (i = 0; i < lena; i++) {
            if (a[i] != b[i]) cnt++;
        }
        if (cnt < min) min = cnt;
    }
    printf("%d", min);
}
