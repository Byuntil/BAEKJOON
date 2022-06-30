#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long A, B;
int mini = 10000;

void input() {
    cin >> A >> B;
}

void dfs(long long a, int cnt) {
    if (a > B) {
        return;
    }
    if (a == B) {
        mini = min(mini, cnt);
    }
    dfs(a * 2, cnt + 1);
    dfs(a * 10 + 1, cnt + 1);
}

void solution() {
    dfs(A, 1);
}

void solve() {
    input();
    solution();
}

void printResult() {
    if (mini == 10000) {
        cout << -1;
    } else {
        cout << mini;
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