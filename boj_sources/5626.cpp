// BOJ 5626 제단
// Dynamic Programming 
​
#include <iostream>
using namespace std;
#define div (1e9+7)
​
int n, height[10001], dp[10001][5000] = {};
​
int main() {
   cin.tie(NULL); cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    
   cin >> n;
​
   for (int i = 0; i < n; ++i)
      cin >> height[i];
​
   dp[0][0] = height[0] == 0 || height[0] == -1;
   for (int i = 1; i < n; ++i) {
      if (height[i] == -1) {
         for (int j = 0; j < 5000; ++j) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % (int)div;
​
            if (j + 1 < 5000)
               dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % (int)div;
​
            if (j - 1 >= 0)
               dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % (int)div;
         }
      }
      else {
         if (height[i] >= 5000)
            continue;
​
         dp[i][height[i]] = (dp[i][height[i]] + dp[i - 1][height[i]]) % (int)div;
​
         if (height[i] + 1 < 5000)
            dp[i][height[i]] = (dp[i][height[i]] + dp[i - 1][height[i] + 1]) % (int)div;
​
         if (height[i] - 1 >= 0)
            dp[i][height[i]] = (dp[i][height[i]] + dp[i - 1][height[i] - 1]) % (int)div;
      }
   }
​
   cout << dp[n - 1][0];
}
