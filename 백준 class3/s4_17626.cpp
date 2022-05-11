#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int arr[50001];

void input() {
    cin >> n;
}

void solution() {
    arr[1] = 1;
    for (int i = 1; i <= n; i++) {
        arr[i] = arr[1] + arr[i - 1];
        for (int j = 2; j * j <= i; j++) {
            arr[i] = min(arr[i], 1 + arr[i - j * j]);
        }
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << arr[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}