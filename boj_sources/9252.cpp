#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
char* LCS(char* a, char* b);
#define NEITHER 0
#define UP 1
#define LEFT 2
#define UP_AND_LEFT 3
char a[1001], b[1001];
int main() {
    cin >> a >> b;
    printf("%d\n%s", strlen(LCS(a,b)), LCS(a,b));
    
}
char* LCS(char* a, char* b) {
    int n = strlen(a); int m = strlen(b);
    int** S; int** R; int ii; int jj;
    int pos; char* lcs;
    S = (int**)malloc((n + 1) * sizeof(int*));
    R = (int**)malloc((n + 1) * sizeof(int*));
    for (ii = 0; ii <= n; ++ii) {
        S[ii] = (int*)malloc((m + 1) * sizeof(int));
        R[ii] = (int*)malloc((m + 1) * sizeof(int));
    }
    for (ii = 0; ii <= n; ++ii) {
        S[ii][0] = 0; R[ii][0] = UP;
    }
    for (jj = 0; jj <= m; ++jj) {
        S[0][jj] = 0; R[0][jj] = LEFT;
    }
    for (ii = 1; ii <= n; ++ii) {
        for (jj = 1; jj <= m; ++jj) {
            if (a[ii - 1] == b[jj - 1]) {
                S[ii][jj] = S[ii - 1][jj - 1] + 1;
                R[ii][jj] = UP_AND_LEFT;
            }
            else {
                S[ii][jj] = S[ii - 1][jj - 1] + 0;
                R[ii][jj] = NEITHER;
            }
            if (S[ii - 1][jj] >= S[ii][jj]) {
                S[ii][jj] = S[ii - 1][jj];
                R[ii][jj] = UP;
            }
            if (S[ii][jj - 1] >= S[ii][jj]) {
                S[ii][jj] = S[ii][jj - 1];
                R[ii][jj] = LEFT;
            }
        }
    }
    ii = n;
    jj = m;
    pos = S[ii][jj];
    lcs = (char*)malloc((pos + 1) * sizeof(char));
    lcs[pos--] = (char)NULL;
    while (ii > 0 || jj > 0) {
        if (R[ii][jj] == UP_AND_LEFT) {
            ii--; jj--;
            lcs[pos--] = a[ii];
        }
        else if (R[ii][jj] == UP) {
            ii--;
        }
        else if (R[ii][jj] == LEFT) {
            jj--;
        }
    }
    for (ii = 0; ii <= n; ++ii) {
        free(S[ii]); free(R[ii]);
    }
    free(S);
    free(R);
    return lcs;
}
​
