#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, k, a, b, c;
vector<pair<int, pair<int, int>>> v;
int tmp[101][101];
int arr[101][101];
int vis[7];
void go(int a, int b, int c) {
    memset(tmp, 0, sizeof(tmp));
​
    int x1 = a - c, y1 = b - c;
    int x2 = a + c, y2 = b + c;
    //두 값이 같아지거나 역전되면 와일문 종료
    while (x1 < x2 && y1 < y2) {
​
        //네 꼭지점 먼저 받기
        tmp[x1][y1] = arr[x1 + 1][y1];
        tmp[x1][y2] = arr[x1][y2 - 1];
        tmp[x2][y1] = arr[x2][y1 + 1];
        tmp[x2][y2] = arr[x2 - 1][y2];
​
        //상단 라인
        for (int j = y1 + 1; j < y2; j++) {
            tmp[x1][j] = arr[x1][j - 1];
        }//하단 라인
​
        for (int j = y1 + 1; j < y2; j++) {
            tmp[x2][j] = arr[x2][j + 1];
        }//좌측 라인
​
        for (int j = x1 + 1; j < x2; j++) {
            tmp[j][y1] = arr[j + 1][y1];
        }//우측 라인
​
        for (int j = x1 + 1; j < x2; j++) {
            tmp[j][y2] = arr[j - 1][y2];
        }
​
        //좌상단 우하단 점 한칸씩 안쪽으로 이동
        x1++, y1++;
        x2--, y2--;
    }
​
    //while문 종료시에 바뀌지 않은 가운데 값들 tmp에 저장
    for (int i = a - c; i <= a + c; i++) {
        for (int j = b - c; j <= b + c; j++) {
            if (tmp[i][j] == 0) {
                tmp[i][j] = arr[i][j];
            }
        }
    }
​
    //tmp배열 값 다시 원래 배열에 넣기
    for (int i = a - c; i <= a + c; i++) {
        for (int j = b - c; j <= b + c; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}
vector < pair<int, pair<int, int>>>vv;
int ans = 123123123;
int tmp2[101][101];
void ggo(int cnt) {
    if (vv.size() == k) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                tmp2[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < vv.size(); i++) {
            go(vv[i].first, vv[i].second.first, vv[i].second.second);
        }
        
        for (int i = 1; i <= n; i++) {
            int score = 0;
            for (int j = 1; j <= m; j++) {
                score += arr[i][j];
            }
            ans = min(ans, score);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                arr[i][j] = tmp2[i][j];
            }
        }
        return;
    }
        for (int i = 0; i < k; i++) {
            if (vis[i]) continue;
            vis[i] = 1;
            vv.push_back({ v[i].first, {v[i].second.first, v[i].second.second} });
            ggo(cnt + 1);
            vv.pop_back();
            vis[i] = 0;
        }
}
​
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    int tt = k;
    while (k--) {
        cin >> a >> b >> c;
        v.push_back({ a, { b, c } });
    }
    k = tt;
    ggo(0);
​
    cout << ans;
}
