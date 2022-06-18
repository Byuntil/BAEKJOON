#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int N, M, H, result;
int box[102][102][102];

bool tomatoState;
int dR[] = {0, 0, 1, -1, 0, 0};
int dC[] = {1, -1, 0, 0, 0, 0};
int dH[] = {0, 0, 0, 0, 1, -1};
queue<pair<pair<int, int>, int>> q; //{{r,c},h}

bool checkTomato();

void input() {
    tomatoState = true;
    cin >> M >> N >> H;
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) { //r
            for (int j = 0; j < M; j++) { //c
                cin >> box[i][j][h];
                if (box[i][j][h] == 0) {
                    tomatoState = false;
                } else if (box[i][j][h] == 1) {
                    q.push({{i, j}, h});
                }
            }
        }
    }
}

void BFS() {
    while (!q.empty()) {
        int qSize = q.size();
        for (int qs = 0; qs < qSize; qs++) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int h = q.front().second;
            q.pop();

            for (int i = 0; i < 6; i++) {
                int nextR = r + dR[i];
                int nextC = c + dC[i];
                int nextH = h + dH[i];

                if (nextR >= 0 && nextC >= 0 && nextH >= 0 && nextR < N && nextC < M && nextH < H) {
                    if (box[nextR][nextC][nextH] == 0) {
                        box[nextR][nextC][nextH] = 1;
                        q.push({{nextR, nextC}, nextH});
                    }
                }
            }
            if (q.size() == 0 && checkTomato() == true) {
                cout << result << "\n";
                return;
            } else if (q.size() == 0 && checkTomato() == false) {
                cout << -1 << "\n";
                return;
            }
        }
        result++;
    }
}

bool checkTomato() {
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) { //r
            for (int j = 0; j < M; j++) { //c
                if (box[i][j][h] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void solution() {
    if (tomatoState == true) {
        cout << 0 << "\n";
        return;
    }
    BFS();
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