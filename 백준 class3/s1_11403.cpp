#include<iostream>
#include<algorithm>

using namespace std;

int N;
int g[101][101];

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
        }
    }

}

void solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (g[j][i] && g[i][k]) {
                    g[j][k] = 1;
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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
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