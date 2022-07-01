#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[1010];
int dp[1010];
int answer;

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

void solution() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
                if (dp[i] > answer) {
                    answer = dp[i];
                }
            }
        }
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}