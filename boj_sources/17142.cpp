#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
​
const int MAX = 50;
const int INF = 987654321;
​
typedef struct
{
    int y, x;
}Dir;
​
Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
​
int N, M;
int result;
bool flag;
int arr[MAX][MAX];
int copyArr[MAX][MAX];
vector<pair<int, int>> virus;
vector<int> temp;
​
void DFS(int cnt)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            copyArr[i][j] = arr[i][j];
​
    queue<pair<int, int>> q;
    for (int i = 0; i < temp.size(); i++)
        if (temp[i])
        {
            q.push(virus[i]);
            copyArr[virus[i].first][virus[i].second] = 3;
        }
​
    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (!cnt)
        {
            flag = true;
            result = min(result, time);
            break;
        }
​
        time++;
        for (int i = 0; i < size; i++)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
​
            for (int j = 0; j < 4; j++)
            {
                int nextY = y + moveDir[j].y;
                int nextX = x + moveDir[j].x;
​
                if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
                    if (!copyArr[nextY][nextX] || copyArr[nextY][nextX] == 2)
                    {
                        if (!copyArr[nextY][nextX])
                            cnt--;
                        copyArr[nextY][nextX] = 3;
                        q.push({ nextY, nextX });
                    }
            }
        }
    }
    return;
}
​
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
​
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                virus.push_back({ i, j });
        }
​
    sort(virus.begin(), virus.end());
    result = INF;
    temp.resize(virus.size());
    for (int i = 0; i < temp.size(); i++)
        temp[i] = 0;
    for (int i = 0; i < M; i++)
        temp[i] = 1;
​
    sort(temp.begin(), temp.end());
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (arr[i][j] == 0)
                cnt++;
​
    do
    {
        DFS(cnt);
    } while (next_permutation(temp.begin(), temp.end()));
​
    if (!flag)
        cout << -1 << "\n";
    else
        cout << result << "\n";
    return 0;
}
