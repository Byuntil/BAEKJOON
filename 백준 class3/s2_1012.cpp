#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int T, M, N, K;
int cnt;
int dx[] = {-1, 1, 0, 0}; //왼, 오, 위, 아래
int dy[] = {0, 0, 1, -1}; //왼, 오, 위, 아래
int board[51][51];
bool check[51][51];

void dfs(int y, int x) {
    check[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N) {
            if (board[nextY][nextX] == 1) {
                if (!check[nextY][nextX]) {
                    dfs(nextY, nextX);
                }
            }
        } else {
            continue;
        }
    }
}

void printResult() {
    cout << cnt << "\n";
    memset(check, false, sizeof(check));
    memset(board, 0, sizeof(board));
}

void solution() {
    cnt = 0;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        board[y][x] = 1;
    }
    for (int i = 0; i < N; i++) { //y
        for (int j = 0; j < M; j++) {//x
            if (board[i][j] == 1) {
                if (!check[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
    }
    printResult();
}

void input() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        solution();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    return 0;
}