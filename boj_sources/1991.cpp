#include <iostream>
#include <vector>
using namespace std;
const int MAX = 26;
​
vector<pair<int, bool>> tree[MAX]; 
​
void preOrder(int node)
{
    cout << (char)(node + 'A');
    for (int i = 0; i < tree[node].size(); i++)
        preOrder(tree[node][i].first);
}
​
void inOrder(int node)
{
    //자식이 존재하고 왼쪽 자식이라면
    if (tree[node].size() && tree[node][0].second)
        inOrder(tree[node][0].first);
    cout << (char)(node + 'A');
    //오른쪽 자식만 있다면
    if (tree[node].size() && !tree[node][0].second)
        inOrder(tree[node][0].first);
    //양쪽 자식 다 있다면
    else if (tree[node].size() == 2)
        inOrder(tree[node][1].first);
}
​
​
​
void postOrder(int node)
{
    for (int i = 0; i < tree[node].size(); i++)
        postOrder(tree[node][i].first);
    cout << (char)(node + 'A');
}
​
​
​
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
​
        char a, b, c;
​
        cin >> a >> b >> c;
        if (b != '.')
            tree[a - 'A'].push_back({ b - 'A', true });
        if (c != '.')
            tree[a - 'A'].push_back({ c - 'A', false });
    }
    preOrder(0);
    cout << "\n";
    inOrder(0);
    cout << "\n";
    postOrder(0);
    cout << "\n";
    return 0;
}
