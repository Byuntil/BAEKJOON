#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int DP[1000000];

void input() {
    cin >> N;
}

void solution() {
    for (int i = 2; i <= N; i++) {
        DP[i] = DP[i - 1] + 1;
        if (i % 2 == 0) {
            DP[i] = min(DP[i], DP[i / 2] + 1);
        }
        if (i % 3 == 0) {
            DP[i] = min(DP[i], DP[i / 3] + 1);
        }
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << DP[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}