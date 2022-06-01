#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

queue<pair<int, int>> q;//value, time
bool visited[100001];
int N, K, result;

void input() {
    cin >> N >> K;
    q.push({N, 0});
}

bool valid(int n) {
    if (n < 0 || n > 100000 || visited[n]) {
        return false;
    }
    return true;
}

void bfs() {
    while (!q.empty()) {
        int value = q.front().first;
        int time = q.front().second;
        q.pop();

        if (value == K) {
            result = time;
            break;
        }

        // -1
        if (valid(value - 1)) {
            visited[value - 1] = true;
            q.push({value - 1, time + 1});
        }

        // +1
        if (valid(value + 1)) {
            visited[value + 1] = true;
            q.push({value + 1, time + 1});
        }

        // *2
        if (valid(value * 2)) {
            visited[value * 2] = true;
            q.push({value * 2, time + 1});
        }
    }
}

void solution() {
    bfs();
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