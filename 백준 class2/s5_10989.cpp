#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[10001];

void input() {
    cin >> N;
}

void solution() {
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        arr[a] += 1;
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i << "\n";
        }
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