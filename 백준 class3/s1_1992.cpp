#include<iostream>
#include<algorithm>

using namespace std;

int N;
int board[64][64];

void input() {
    cin >> N;
    for (int r = 0; r < N; r++) {
        string a;
        cin >> a;
        for (int c = 0; c < N; c++) {
            if (a[c] == '1') {
                board[r][c] = 1;
            } else if (a[c] == '0') {
                board[r][c] = 0;
            }
        }
    }
}

void isSame(int R, int C, int size) {
    if (size == 1) {
        cout << board[R][C];
        return;
    }
    bool OnlyZero = true, OnlyOne = true;

    for (int r = R; r < R + size; r++) {
        for (int c = C; c < C + size; c++) {
            if (board[r][c] == 0) {
                OnlyOne = false;
            }
            if (board[r][c] == 1) {
                OnlyZero = false;
            }
        }
    }

    if (OnlyZero) {
        cout << 0;
        return;
    }
    if (OnlyOne) {
        cout << 1;
        return;
    }

    cout << "(";
    isSame(R, C, size / 2);
    isSame(R, C + size / 2, size / 2);
    isSame(R + size / 2, C, size / 2);
    isSame(R + size / 2, C + size / 2, size / 2);
    cout << ")";
}

void solution() {
    isSame(0, 0, N);
}

void solve() {
    input();
    solution();
}

void printResult() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}