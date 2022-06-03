#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M, tmp = 101, result;
int network[101][101];
bool visit[101];
int cnt[101];
queue<int> q;

void input() {
    cin >> N >> N;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        network[a][b] = 1;
        network[b][a] = 1;
    }
}

bool BFS(int num) {
    q.push(num);
    visit[num] = true;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (!visit[i] && network[p][i]) {
                cnt[i] = cnt[p] + 1;
                q.push(i);
                visit[i] = true;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += cnt[i];
    }
    if (sum < tmp) {
        tmp = sum;
        return true;
    } else {
        return false;
    }
}

void solution() {
    for (int i = 1; i <= N; i++) {
        if (BFS(i))
            result = i;
        memset(visit, false, sizeof(visit));
        memset(cnt, 0, sizeof(cnt));
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}