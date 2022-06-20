#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int N, M, result;
int board[501][501];
bool visit[501][501];

int dR[] = {0, 0, -1, 1};
int dC[] = {1, -1, 0, 0};

void shape1(int r, int c);

void shape2(int r, int c);

void shape3(int r, int c);

void shape4(int r, int c);

void input() {
    cin >> N >> M;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> board[r][c];
        }
    }
}

void dfs(int r, int c, int sum, int cnt) {
    visit[r][c] = true;
    if (cnt == 3) {
        result = max(result, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nextR = r + dR[i];
        int nextC = c + dC[i];

        if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) {
            continue;
        }
        if (visit[nextR][nextC] == true) {
            continue;
        }
        dfs(nextR, nextC, sum + board[nextR][nextC], cnt + 1);
        visit[nextR][nextC] = false;
    }
}

void solution() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            memset(visit, false, sizeof(visit));
            dfs(r, c, board[r][c], 0);
            if (r - 1 >= 0 && c + 2 < M) {
                shape1(r, c);
            }
            if (r + 1 < N && c + 2 < M) {
                shape2(r, c);
            }
            if (r + 2 < N && c + 1 < M) {
                shape3(r, c);
            }
            if (r + 1 < N && r - 1 >= 0 && c + 1 < M) {
                shape4(r, c);
            }
        }
    }
}

void shape1(int r, int c) {
    int sum = 0;
    sum = board[r][c] + board[r][c + 1] + board[r][c + 2] + board[r - 1][c + 1];
    if (sum > result) {
        result = sum;
    }
}

void shape2(int r, int c) {
    int sum = 0;
    sum = board[r][c] + board[r][c + 1] + board[r][c + 2] + board[r + 1][c + 1];
    if (sum > result) {
        result = sum;
    }
}

void shape3(int r, int c) {
    int sum = 0;
    sum = board[r][c] + board[r + 1][c] + board[r + 2][c] + board[r + 1][c + 1];
    if (sum > result) {
        result = sum;
    }
}

void shape4(int r, int c) {
    int sum = 0;
    sum = board[r][c] + board[r - 1][c + 1] + board[r][c + 1] + board[r + 1][c + 1];
    if (sum > result) {
        result = sum;
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