#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

int T, a, b;
bool visit[10000];

void bfs();

void input() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        memset(visit, false, sizeof(visit));
        bfs();
    }
}

void bfs() {
    queue <pair<int, string>> q;
    q.push({a, ""});
    visit[a] = true;

    while (!q.empty()) {
        int num = q.front().first;
        string numString = q.front().second;
        q.pop();

        if (num == b) {
            cout << numString << "\n";
            return;
        }

        int d, s, l, r;

        d = (num * 2) % 10000;
        if (!visit[d]) {
            visit[d] = true;
            q.push({d, numString + 'D'});
        }

        s = num - 1;
        if (num == 0) {
            s = 9999;
        }
        if (!visit[s]) {
            visit[s] = true;
            q.push({s, numString + 'S'});
        }

        l = (num % 1000) * 10 + (num / 1000);
        if (!visit[l]) {
            visit[l] = true;
            q.push({l, numString + 'L'});
        }

        r = (num / 10) + (num % 10) * 1000;
        if (!visit[r]) {
            visit[r] = true;
            q.push({r, numString + 'R'});
        }
    }
}

void solve() {
    input();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}