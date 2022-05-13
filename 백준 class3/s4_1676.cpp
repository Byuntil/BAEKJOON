#include<iostream>
#include<algorithm>

using namespace std;

int N;
int a1, a2, a3;

void input() {
    cin >> N;
}

void solution() {
    a1 = N / 5;
    a2 = N / 25;
    a3 = N / 125;
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << a1 + a2 + a3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}