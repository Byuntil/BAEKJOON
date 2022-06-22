#include<iostream>
#include<cmath>

using namespace std;

int N, M;
bool broken[10];
int result;

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        broken[a] = true;
    }
}

int check(int n) {
    if (n == 0) {
        if (broken[0]) {
            return 0;
        } else {
            return 1;
        }
    }
    int len = 0;
    while (n > 0) {
        if (broken[n % 10]) {
            return 0;
        }
        n /= 10;
        len += 1;
    }
    return len;
}

void solution() {
    result = abs(N - 100);
    for (int i = 0; i <= 1000000; i++) {
        int c = i;
        int len = check(c);
        if (len > 0) {
            int press = abs(c - N);
            if (result > press + len) {
                result = press + len;
            }
        }
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}