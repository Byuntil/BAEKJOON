#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

//이상하게 자꾸 오류남.,...
using namespace std;

int N, M, result = -1;
int board[1001][1001];
int day[1001][1001];
bool visit[1001][1001];
int dR[4] = {0, 0, 1, -1}; //오,왼,위,아래
int dC[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;


void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) { //r
        for (int j = 0; j < M; j++) {//c
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
}

void BFS() {
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextR = r + dR[i];
            int nextC = c + dC[i];

            if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) {
                continue;
            }
            if (board[nextR][nextC] == 0 && visit[nextR][nextC] == 0) {
                visit[nextR][nextC] = true;
                day[nextR][nextC] = day[r][c] + 1;
                q.push({nextR, nextC});
            }
        }
    }
}

void solution() {
    BFS();
}

void solve() {
    input();
    solution();
}

void printResult() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0 && day[i][j] == 0) {
                cout << "-1";
                return;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (day[i][j] > result) {
                result = day[i][j];
            }
        }
    }

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