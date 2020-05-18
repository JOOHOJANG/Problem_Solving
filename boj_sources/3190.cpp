#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> ppi;
int vis[101][101];
int app[101][101];
vector<ppi> cmd;
vector<pii> sn;
​
int n;
int ap, cm;
int ans;
void go(int cnt,int dir) {
    if (dir == 1) {
        if (cmd.size()) {
            if (cmd[cmd.size() - 1].first == cnt) {
                if (cmd[cmd.size() - 1].second == 'D') {
                    int x = sn[0].first + 1;
                    int y = sn[0].second;
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        ans = cnt + 1;
                        return;
                    }
                    for (int i = 0; i < sn.size(); i++) {
                        if (sn[i].first == x && sn[i].second == y) {
                            ans = cnt + 1;
                            return;
                        }
                    }
                    if (app[x][y]) {
                        app[x][y] = 0;
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                        sn.push_back(last);
                    }
                    else {
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                    }
                    cmd.pop_back();
                    go(cnt + 1, 2);
                }
                else {
                    int x = sn[0].first - 1;
                    int y = sn[0].second;
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        ans = cnt + 1;
                        return;
                    }
                    for (int i = 0; i < sn.size(); i++) {
                        if (sn[i].first == x && sn[i].second == y) {
                            ans = cnt + 1;
                            return;
                        }
                    }
                    if (app[x][y]) {
                        app[x][y] = 0;
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                        sn.push_back(last);
                    }
                    else {
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                    }
                    cmd.pop_back();
                    go(cnt + 1, 4);
                }
            }
            else {
                int x = sn[0].first;
                int y = sn[0].second + 1;
                if (x < 0 || x >= n || y < 0 || y >= n) {
                    ans = cnt + 1;
                    return;
                }
                for (int i = 0; i < sn.size(); i++) {
                    if (sn[i].first == x && sn[i].second == y) {
                        ans = cnt + 1;
                        return;
                    }
                }
                if (app[x][y]) {
                    app[x][y] = 0;
                    pii last = sn[sn.size() - 1];
                    for (int i = sn.size() - 1; i >= 1; i--) {
                        sn[i] = sn[i - 1];
                    }
                    sn[0] = make_pair(x, y);
                    sn.push_back(last);
                }
                else {
                    pii last = sn[sn.size() - 1];
                    for (int i = sn.size() - 1; i >= 1; i--) {
                        sn[i] = sn[i - 1];
                    }
                    sn[0] = make_pair(x, y);
                }
                go(cnt + 1, dir);
            }
        }
        else {
            int x = sn[0].first;
            int y = sn[0].second + 1;
            if (x < 0 || x >= n || y < 0 || y >= n) {
                ans = cnt + 1;
                return;
            }
            for (int i = 0; i < sn.size(); i++) {
                if (sn[i].first == x && sn[i].second == y) {
                    ans = cnt + 1;
                    return;
                }
            }
            if (app[x][y]) {
                app[x][y] = 0;
                pii last = sn[sn.size() - 1];
                for (int i = sn.size() - 1; i >= 1; i--) {
                    sn[i] = sn[i - 1];
                }
                sn[0] = make_pair(x, y);
                sn.push_back(last);
            }
            else {
                pii last = sn[sn.size() - 1];
                for (int i = sn.size() - 1; i >= 1; i--) {
                    sn[i] = sn[i - 1];
                }
                sn[0] = make_pair(x, y);
            }
            go(cnt + 1, dir);
        }
    }
    if (dir == 2) {
        if (cmd.size()) {
            if (cmd[cmd.size() - 1].first == cnt) {
                if (cmd[cmd.size() - 1].second == 'D') {
                    int x = sn[0].first;
                    int y = sn[0].second - 1;
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        ans = cnt + 1;
                        return;
                    }
                    for (int i = 0; i < sn.size(); i++) {
                        if (sn[i].first == x && sn[i].second == y) {
                            ans = cnt + 1;
                            return;
                        }
                    }
                    if (app[x][y]) {
                        app[x][y] = 0;
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                        sn.push_back(last);
                    }
                    else {
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                    }
                    cmd.pop_back();
                    go(cnt + 1, 3);
                }
                else {
                    int x = sn[0].first;
                    int y = sn[0].second + 1;
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        ans = cnt + 1;
                        return;
                    }
                    for (int i = 0; i < sn.size(); i++) {
                        if (sn[i].first == x && sn[i].second == y) {
                            ans = cnt + 1;
                            return;
                        }
                    }
                    if (app[x][y]) {
                        app[x][y] = 0;
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                        sn.push_back(last);
                    }
                    else {
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                    }
                    cmd.pop_back();
                    go(cnt + 1, 1);
                }
            }
            else {
                int x = sn[0].first+1;
                int y = sn[0].second;
                if (x < 0 || x >= n || y < 0 || y >= n) {
                    ans = cnt + 1;
                    return;
                }
                for (int i = 0; i < sn.size(); i++) {
                    if (sn[i].first == x && sn[i].second == y) {
                        ans = cnt + 1;
                        return;
                    }
                }
                if (app[x][y]) {
                    app[x][y] = 0;
                    pii last = sn[sn.size() - 1];
                    for (int i = sn.size() - 1; i >= 1; i--) {
                        sn[i] = sn[i - 1];
                    }
                    sn[0] = make_pair(x, y);
                    sn.push_back(last);
                }
                else {
                    pii last = sn[sn.size() - 1];
                    for (int i = sn.size() - 1; i >= 1; i--) {
                        sn[i] = sn[i - 1];
                    }
                    sn[0] = make_pair(x, y);
                }
                go(cnt + 1, dir);
            }
        }
        else {
            int x = sn[0].first+1;
            int y = sn[0].second;
            if (x < 0 || x >= n || y < 0 || y >= n) {
                ans = cnt + 1;
                return;
            }
            for (int i = 0; i < sn.size(); i++) {
                if (sn[i].first == x && sn[i].second == y) {
                    ans = cnt + 1;
                    return;
                }
            }
            if (app[x][y]) {
                app[x][y] = 0;
                pii last = sn[sn.size() - 1];
                for (int i = sn.size() - 1; i >= 1; i--) {
                    sn[i] = sn[i - 1];
                }
                sn[0] = make_pair(x, y);
                sn.push_back(last);
            }
            else {
                pii last = sn[sn.size() - 1];
                for (int i = sn.size() - 1; i >= 1; i--) {
                    sn[i] = sn[i - 1];
                }
                sn[0] = make_pair(x, y);
            }
            go(cnt + 1, dir);
        }
    }
    if (dir == 3) {
        if (cmd.size()) {
            if (cmd[cmd.size() - 1].first == cnt) {
                if (cmd[cmd.size() - 1].second == 'D') {
                    int x = sn[0].first - 1;
                    int y = sn[0].second;
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        ans = cnt + 1;
                        return;
                    }
                    for (int i = 0; i < sn.size(); i++) {
                        if (sn[i].first == x && sn[i].second == y) {
                            ans = cnt + 1;
                            return;
                        }
                    }
                    if (app[x][y]) {
                        app[x][y] = 0;
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                        sn.push_back(last);
                    }
                    else {
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                    }
                    cmd.pop_back();
                    go(cnt + 1, 4);
                }
                else {
                    int x = sn[0].first + 1;
                    int y = sn[0].second;
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        ans = cnt + 1;
                        return;
                    }
                    for (int i = 0; i < sn.size(); i++) {
                        if (sn[i].first == x && sn[i].second == y) {
                            ans = cnt + 1;
                            return;
                        }
                    }
                    if (app[x][y]) {
                        app[x][y] = 0;
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                        sn.push_back(last);
                    }
                    else {
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                    }
                    cmd.pop_back();
                    go(cnt + 1, 2);
                }
            }
            else {
                int x = sn[0].first;
                int y = sn[0].second- 1;
                if (x < 0 || x >= n || y < 0 || y >= n) {
                    ans = cnt + 1;
                    return;
                }
                for (int i = 0; i < sn.size(); i++) {
                    if (sn[i].first == x && sn[i].second == y) {
                        ans = cnt + 1;
                        return;
                    }
                }
                if (app[x][y]) {
                    app[x][y] = 0;
                    pii last = sn[sn.size() - 1];
                    for (int i = sn.size() - 1; i >= 1; i--) {
                        sn[i] = sn[i - 1];
                    }
                    sn[0] = make_pair(x, y);
                    sn.push_back(last);
                }
                else {
                    pii last = sn[sn.size() - 1];
                    for (int i = sn.size() - 1; i >= 1; i--) {
                        sn[i] = sn[i - 1];
                    }
                    sn[0] = make_pair(x, y);
                }
                go(cnt + 1, dir);
            }
        }
        else {
            int x = sn[0].first;
            int y = sn[0].second-1;
            if (x < 0 || x >= n || y < 0 || y >= n) {
                ans = cnt + 1;
                return;
            }
            for (int i = 0; i < sn.size(); i++) {
                if (sn[i].first == x && sn[i].second == y) {
                    ans = cnt + 1;
                    return;
                }
            }
            if (app[x][y]) {
                app[x][y] = 0;
                pii last = sn[sn.size() - 1];
                for (int i = sn.size() - 1; i >= 1; i--) {
                    sn[i] = sn[i - 1];
                }
                sn[0] = make_pair(x, y);
                sn.push_back(last);
            }
            else {
                pii last = sn[sn.size() - 1];
                for (int i = sn.size() - 1; i >= 1; i--) {
                    sn[i] = sn[i - 1];
                }
                sn[0] = make_pair(x, y);
            }
            go(cnt + 1, dir);
        }
    }
    if (dir == 4) {
        if (cmd.size()) {
            if (cmd[cmd.size() - 1].first == cnt) {
                if (cmd[cmd.size() - 1].second == 'D') {
                    int x = sn[0].first;
                    int y = sn[0].second + 1;
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        ans = cnt + 1;
                        return;
                    }
                    for (int i = 0; i < sn.size(); i++) {
                        if (sn[i].first == x && sn[i].second == y) {
                            ans = cnt + 1;
                            return;
                        }
                    }
                    if (app[x][y]) {
                        app[x][y] = 0;
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                        sn.push_back(last);
                    }
                    else {
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                    }
                    cmd.pop_back();
                    go(cnt + 1, 1);
                }
                else {
                    int x = sn[0].first;
                    int y = sn[0].second - 1;
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        ans = cnt + 1;
                        return;
                    }
                    for (int i = 0; i < sn.size(); i++) {
                        if (sn[i].first == x && sn[i].second == y) {
                            ans = cnt + 1;
                            return;
                        }
                    }
                    if (app[x][y]) {
                        app[x][y] = 0;
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                        sn.push_back(last);
                    }
                    else {
                        pii last = sn[sn.size() - 1];
                        for (int i = sn.size() - 1; i >= 1; i--) {
                            sn[i] = sn[i - 1];
                        }
                        sn[0] = make_pair(x, y);
                    }
                    cmd.pop_back();
                    go(cnt + 1, 3);
                }
            }
            else {
                int x = sn[0].first-1;
                int y = sn[0].second;
                if (x < 0 || x >= n || y < 0 || y >= n) {
                    ans = cnt + 1;
                    return;
                }
                for (int i = 0; i < sn.size(); i++) {
                    if (sn[i].first == x && sn[i].second == y) {
                        ans = cnt + 1;
                        return;
                    }
                }
                if (app[x][y]) {
                    app[x][y] = 0;
                    pii last = sn[sn.size() - 1];
                    for (int i = sn.size() - 1; i >= 1; i--) {
                        sn[i] = sn[i - 1];
                    }
                    sn[0] = make_pair(x, y);
                    sn.push_back(last);
                }
                else {
                    pii last = sn[sn.size() - 1];
                    for (int i = sn.size() - 1; i >= 1; i--) {
                        sn[i] = sn[i - 1];
                    }
                    sn[0] = make_pair(x, y);
                }
                go(cnt + 1, dir);
            }
        }
        else {
            int x = sn[0].first-1;
            int y = sn[0].second;
            if (x < 0 || x >= n || y < 0 || y >= n) {
                ans = cnt + 1;
                return;
            }
            for (int i = 0; i < sn.size(); i++) {
                if (sn[i].first == x && sn[i].second == y) {
                    ans = cnt + 1;
                    return;
                }
            }
            if (app[x][y]) {
                app[x][y] = 0;
                pii last = sn[sn.size() - 1];
                for (int i = sn.size() - 1; i >= 1; i--) {
                    sn[i] = sn[i - 1];
                }
                sn[0] = make_pair(x, y);
                sn.push_back(last);
            }
            else {
                pii last = sn[sn.size() - 1];
                for (int i = sn.size() - 1; i >= 1; i--) {
                    sn[i] = sn[i - 1];
                }
                sn[0] = make_pair(x, y);
            }
            go(cnt + 1, dir);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> ap;
    int a, b;
    char bb;
​
​
    for (int i = 0; i < ap; i++) {
        cin >> a >> b;
        app[a-1][b-1] = 1;
    }
    cin >> cm;
    for (int i = 0; i < cm; i++) {
        cin >> a >> bb;
        cmd.push_back({ a, bb });
    }
    reverse(cmd.begin(), cmd.end());
    sn.push_back({ 0, 0 });
    go(0, 1);
    cout << ans;
}
