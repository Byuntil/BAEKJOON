#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int N;
int board[22][22];
int visit[22][22];
int dR[] = {-1, 1, 0, 0};
int dC[] = {0, 0, -1, 1};
int second, R, C, eatFish, babySize = 2;


void input() {
    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> board[r][c];
            if (board[r][c] == 9) {
                R = r;
                C = c;
            }
        }
    }
}

int bfs() {
    queue <pair<int, int>> q;
    vector <pair<int, int>> fish;
    if (eatFish >= babySize) {
        eatFish -= babySize;
        babySize++;
    }
    q.push({R, C});
    while (!q.empty()) {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextR = curR + dR[i];
            int nextC = curC + dC[i];
            if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) {
                continue;
            }
            if (visit[nextR][nextC] != -1) {
                continue;
            }
            if (board[nextR][nextC] > babySize) {
                continue;
            } else if (board[nextR][nextC] == babySize || board[nextR][nextC] == 0) {
                visit[nextR][nextC] = visit[curR][curC] + 1;
                q.push({nextR, nextC});
            } else if (board[nextR][nextC] < babySize && board[nextR][nextC] >= 1) {
                visit[nextR][nextC] = visit[curR][curC] + 1;
                fish.push_back({nextR, nextC});
                q.push({nextR, nextC});
            }
        }
    }
    if (fish.size() == 0) {
        cout << second << "\n";
        return -1;
    } else if (fish.size() == 1) {
        R = fish[0].first;
        C = fish[0].second;
        board[R][C] = 0;
        eatFish++;
        second += visit[R][C];
    } else {
        int mindist = 1e5;
        for (auto &x: fish) {
            mindist = min(mindist, visit[x.first][x.second]);
        }
        vector <pair<int, int>> minfish;
        for (auto &x: fish) {
            if (mindist == visit[x.first][x.second]) {
                minfish.push_back({x.first, x.second});
            }
        }
        if (minfish.size() == 1) {
            R = minfish[0].first;
            C = minfish[0].second;
            board[R][C] = 0;
            second += visit[R][C];
            eatFish++;
        } else {
            sort(minfish.begin(), minfish.end());
            R = minfish[0].first;
            C = minfish[0].second;
            second += visit[R][C];
            board[R][C] = 0;
            eatFish++;
        }
    }
}

void solution() {
    while (true) {
        memset(visit, -1, sizeof(visit));
        visit[R][C] = 0;
        board[R][C] = 0;
        if (bfs() == -1) {
            break;
        }
    }
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