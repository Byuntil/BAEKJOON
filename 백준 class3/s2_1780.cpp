#include<iostream>
#include<algorithm>

using namespace std;

int answer[3]; //-1, 0, 1
int N;
int board[2190][2190];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
}

bool isSame(int x, int y, int n) {
    int check = board[x][y];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[x + i][y + j] != check) {
                return false;
            }
        }
    }
    return true;
}

void cutting(int x, int y, int n) {
    if (isSame(x, y, n)) {
        int num = board[x][y];
        answer[num + 1]++;
        return;
    }

    //분할 정복
    int div = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cutting(x + div * i, y + div * j, div);
        }
    }
}

void solution() {
    cutting(0, 0, N);
}

void solve() {
    input();
    solution();
}

void printResult() {
    for (int i = 0; i < 3; i++) {
        cout << answer[i] << "\n";
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