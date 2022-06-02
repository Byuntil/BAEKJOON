#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N, M;
int board[101][101]; //r,c
int visit[101][101]; //r,c
int rD[4] = {1, 0, -1, 0};
int cD[4] = {0, 1, 0, -1};
int check[101][101]; //각 거리 표시

bool isValid(int r, int c);

void input() {
    cin >> N >> M;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            scanf("%1d", &board[r][c]);
        }
    }
}

bool isValid(int r, int c) {
    if (0 < r && r <= N && 0 < c && c <= M) {
        if (!visit[r][c] && board[r][c] == 1) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void bfs(int r, int c) {
    queue <pair<int, int>> q;
    q.push({r, c});
    visit[r][c] = true;
    check[r][c] = 1;

    while (!q.empty()) {
        int currentR = q.front().first;
        int currentC = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextR = currentR + rD[i];
            int nextC = currentC + cD[i];
            if (isValid(nextR, nextC)) {
                check[nextR][nextC] = check[currentR][currentC] + 1;
                visit[nextR][nextC] = true;
                q.push({nextR, nextC});
            }
        }
    }
}


void solution() {
    bfs(1, 1);
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << check[N][M];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}