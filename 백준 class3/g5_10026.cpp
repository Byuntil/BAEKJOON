#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int N, result;
char board[101][101];
bool visit[101][101];

int dR[] = {0, 0, -1, 1};
int dC[] = {-1, 1, 0, 0};

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            board[i][j] = s[j];
        }
    }
}

void dfs(int r, int c) {
    visit[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nextR = r + dR[i];
        int nextC = c + dC[i];

        if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) {
            continue;
        }
        if (!visit[nextR][nextC] && board[r][c] == board[nextR][nextC]) {
            dfs(nextR, nextC);
        }
    }
}

void solution() {
    //적록색약 x
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                dfs(i, j);
                result++;
            }
        }
    }
    cout << result << " ";
    result = 0;
    memset(visit, false, sizeof(visit));
    //적록색약
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'G') {
                board[i][j] = 'R';
            } else {
                board[i][j] = board[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                dfs(i, j);
                result++;
            }
        }
    }

    cout << result;
}

void solve() {
    input();
    solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}