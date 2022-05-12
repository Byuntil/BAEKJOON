#include<iostream>
#include<algorithm>
#include<cmath>

//분할 정복법
using namespace std;

int N, r, c; //r: 행, c: 열
int cnt;

void input() {
    cin >> N >> r >> c;
}

void z(int y, int x, int size) {
    if (y == r && x == c) {
        cout << cnt << "\n";
        return;
    }

    if (r < y + size && r >= y && c < x + size && c >= x) {
        z(y, x, size / 2);
        z(y, x + size / 2, size / 2);
        z(y + size / 2, x, size / 2);
        z(y + size / 2, x + size / 2, size / 2);
    } else {
        cnt += size * size;
    }
}

void solution() {
    z(0, 0, pow(2, N));
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