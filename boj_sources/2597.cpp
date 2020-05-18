#define CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
​
double l, r, fold;
double mid;
double r1, r2, b1, b2, yy1, y2;
​
void go() {
if(r1!=r2){
    mid = (r1 + r2) / 2;
    fold = mid - l;
    if (b1 < mid) b1 = mid + (mid - b1);
    if (b2 < mid) b2 = mid + (mid - b2);
    if (yy1 < mid) yy1 = mid + (mid - yy1);
    if (y2 < mid) y2 = mid + (mid - y2);
    l = mid;
    r = r > mid + fold ? r : (fold + mid);
}
if(b1!=b2){
    mid = (b1 + b2) / 2;
    fold = mid - l;
    if (yy1 < mid) yy1 = mid + (mid - yy1);
    if (y2 < mid) y2 = mid + (mid - y2);
    l = mid;
    r = r > mid + fold ? r : (fold + mid);
}
if(yy1!=y2){
    mid = (yy1 + y2) / 2;
    fold = mid - l;
    l = mid;
    r = r > mid + fold ? r : (fold + mid);
    }
}
​
int main() {
    cin >> r;
    cin >> r1 >> r2 >> b1 >> b2 >> yy1 >> y2;
    go();
    printf("%.1lf", r - l);
}
