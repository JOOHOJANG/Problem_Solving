#include <iostream>
#include <string>
using namespace std;
​
int main(){
    string s, a;
    int i, j;
    cin >> s;
    int size = s.size();
    for (i = 0; i < size; i++){
        a = s;
        for (j = i - 1; j >= 0; j--)
            a += s[j];
        int asize = a.size();
        for (j = 0; j < asize / 2; j++){
            if (a[j] != a[asize - j - 1]) break;
        }
        if (j == asize / 2){
            cout << asize;
            return 0;
        }
    }
}
