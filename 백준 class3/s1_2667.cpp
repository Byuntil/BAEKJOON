#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int board[25][25];
int visit[25][25];
vector<int> cntV;

int dR[4] = {-1, 0, 1, 0};
int dC[4] = {0, 1, 0, -1};

int N, cnt, res;

void input() {
    cin >> N;
    string s;
    for (int r = 0; r < N; r++) {
        cin >> s;
        for (int c = 0; c < N; c++) {
            if (s[c] == '1') {
                board[r][c] = 1;
            } else {
                board[r][c] = 0;
            }
        }
    }
}

void dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nextR = r + dR[i];
        int nextC = c + dC[i];
        if (nextR >= N || nextR < 0 || nextC >= N || nextC < 0) {
            continue;
        }
        if (visit[nextR][nextC] == 0 && board[nextR][nextC] == 1) {
            visit[nextR][nextC] = 1;
            cnt += 1;
            dfs(nextR, nextC);
        }
    }
}

void solution() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c] == 1 && visit[r][c] == 0) {
                visit[r][c] = 1;
                cnt = 1;
                dfs(r, c);
                cntV.push_back(cnt);
                res++;
            }
        }
    }
}


void solve() {
    input();
    solution();
}

void printResult() {
    sort(cntV.begin(), cntV.end());
    cout << res << "\n";
    for (int i = 0; i < cntV.size(); i++) {
        cout << cntV[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}