#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int dp[505][505]; // r, c

void input() {
    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c <= r; c++) {
            cin >> dp[r][c];
        }
    }
}

void solution() {
    for (int r = N - 1; r >= 1; r--) {
        for (int c = 0; c < r; c++) {
            dp[r - 1][c] += max(dp[r][c], dp[r][c + 1]);
        }
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << dp[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}