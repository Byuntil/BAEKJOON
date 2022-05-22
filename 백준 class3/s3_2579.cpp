#include<iostream>
#include<algorithm>

using namespace std;

int T;
int arr[301];
int dp[301];

void input() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> arr[i];
    }
}

void solution() {
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
    for (int i = 4; i <= T; i++) {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << dp[T];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}