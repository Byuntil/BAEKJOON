#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//지수법칙 : a^(n+m) = a^n * a^m | 모듈러 성질 : (a*b)%c = (a%c * b%c)%c
long long A, B, C;

void input() {
    cin >> A >> B >> C;
}

long long int fu(long long int y) {
    if (y == 1) {
        return A % C;
    }
    long long int k = fu(y / 2) % C;

    if (y % 2 == 0) {
        return k * k % C;
    } else {
        return k * k % C * A % C;
    }
}

void solution() {
    cout << fu(B);
}

void solve() {
    input();
    solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
