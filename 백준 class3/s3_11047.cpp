#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, K, sum;
int v[11];

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
}

void solution() {
    for (int i = N - 1; i >= 0; i--) {
        sum += K / v[i];
        K = K % v[i];
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}