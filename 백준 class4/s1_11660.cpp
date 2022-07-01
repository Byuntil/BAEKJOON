#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int N;
int arr[2][100001];
int dp[2][100001];

void input() {
    cin >> N;
    for (int i = 0; i <= 1; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
}

void solution() {
    dp[0][0] = dp[1][0] = 0;
    dp[0][1] = arr[0][1];
    dp[1][1] = arr[1][1];

    for (int i = 2; i <= N; i++) {
        dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
        dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
    }

    cout << max(dp[0][N], dp[1][N]) << "\n";
}

void solve() {
    int testCase;
    cin >> testCase;
    for (int t = 1; t <= testCase; t++) {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        input();
        solution();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}