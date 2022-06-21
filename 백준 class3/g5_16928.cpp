#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N, M;
int n[102];
int d[102];

void input() {
    for (int i = 1; i <= 100; i++) {
        n[i] = i;
        d[i] = -1;
    }
    cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        int x, y;
        cin >> x >> y;
        n[x] = y;
    }
}

void start(int start) {
    d[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int y = x + i;
            if (y > 100) {
                continue;
            }
            y = n[y];
            if (d[y] == -1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
}

void solution() {
    start(1);
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << d[100];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}