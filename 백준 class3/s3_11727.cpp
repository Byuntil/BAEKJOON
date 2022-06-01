#include<iostream>
#include<algorithm>

using namespace std;

int N;
int dp[1001];

void input() {
    cin >> N;
}

void solution() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= N; i++) {
        dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 10007;
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << dp[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}