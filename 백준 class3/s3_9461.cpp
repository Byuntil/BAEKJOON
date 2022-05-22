#include<iostream>
#include<algorithm>

using namespace std;
int T, N;
long arr[101];

void input() {
    cin >> T;
}

void printResult() {
    cout << arr[N] << "\n";
}

void solution() {
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    arr[6] = 3;
    arr[7] = 4;
    arr[8] = 5;
    arr[9] = 7;
    arr[10] = 9;
    int j = 6;
    for (int i = 11; i <= 100; i++) {
        arr[i] = arr[i - 1] + arr[j++];
    }
    for (int i = 0; i < T; i++) {
        cin >> N;
        printResult();
    }
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