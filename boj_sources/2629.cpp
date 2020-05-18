#include <iostream>
using namespace std;
int nchoo;
int nball;
int choo[30];
int ball[7];
int visited[31][31 * 500 + 1];
char yes[7];
int sum;
int myabs(int a, int b) {
    if (a < b) return -(a - b);
    else return a - b;
}
void backtracking(int numofchoo, int weight) {
    if (numofchoo > nchoo) return;
    if (visited[numofchoo][weight]) return;
    
    visited[numofchoo][weight] = 1;
    
    backtracking(numofchoo + 1, weight + choo[numofchoo]);
    backtracking(numofchoo + 1, weight);
    backtracking(numofchoo + 1, myabs(weight, choo[numofchoo]));
    
}
int main() {
    cin >> nchoo;
    for (int i = 0; i < nchoo; i++) cin >> choo[i], sum+=choo[i];
    cin >> nball;
    for (int i = 0; i < nball; i++) cin >> ball[i];
    backtracking(0, 0);
    for (int i = 0; i < nball; i++) {
        if (sum < ball[i]) {
            cout << "N ";
        }
        else if (sum == ball[i]) {
            cout << "Y ";
        }
        else {
            if (visited[nchoo][ball[i]])
                cout << "Y ";
            else cout << "N ";
        }
    }
}
