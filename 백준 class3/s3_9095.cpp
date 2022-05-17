#include<iostream>
#include<algorithm>

using namespace std;

int T;
int DP[11];

void input() {
    cin >> T;
}

void solution() {
    int n;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 0; i < T; i++) {
        cin >> n;
        for (int j = 4; j <= n; j++) {
            DP[j] = DP[j - 1] + DP[j - 2] + DP[j - 3];
        }
        cout << DP[n] << "\n";
    }
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