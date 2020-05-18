#include <iostream> 
#include <algorithm> 
using namespace std; 
int A, B, N; int ab[100][2];
#define IN(p) ((p).first <= A && (p).second <= B) 
int marea;
​
pair<int, int> new_ab(int c, int d) {
    if (c > d) {
        return make_pair(c, d); 
    } else {
        return make_pair(d, c);
    }
} 
int main() { ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B >> N;
    if (B > A) swap(A, B); 
    for (int i = 0; i < N; ++i)
    {
        cin >> ab[i][0] >> ab[i][1]; 
    } 
    int i, j; 
    for (i = 0; i < N - 1; ++i) {
        for (j = i + 1; j < N; ++j) {
            for (auto k : { 0, 1 }) { 
                for (auto l : { 0, 1 }) {
                    if (IN(new_ab(ab[i][k] + ab[j][l], max(ab[i][1 - k], ab[j][1 - l])))) {
                        int area = ab[i][0] * ab[i][1] + ab[j][0] * ab[j][1]; 
                        if (area > marea) marea = area;
                    }
                }
            }
        }
    }
    cout << marea; return 0; 
}
​
