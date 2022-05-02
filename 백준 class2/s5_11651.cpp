#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<vector<int>> arr(N, vector<int>(2, 0));

void input() {
    for (int i = 0; i < N; i++) {
        cin >> arr[i][1];
        cin >> arr[i][0];
    }
}

void solution() {
    sort(arr.begin(), arr.end());
}

void solve() {
    input();
    solution();
}

void printResult() {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i][1] << " " << arr[i][0] << "\n";
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