#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int arr[9];

void input() {
    cin >> N >> M;
}

void b(int num, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = num; i <= N; i++) {
        arr[cnt] = i;
        b(i, cnt + 1);
    }
}

void solution() {
    b(1, 0);

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