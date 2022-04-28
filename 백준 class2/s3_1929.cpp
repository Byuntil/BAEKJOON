#include<iostream>
#include<algorithm>

using namespace std;

int N,M;
int arr[1000001];

void input() {
    cin>>M>>N;
}

void solution() {
    arr[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 2; i * j <= N; j++) {
            arr[i*j] = 1;
        }
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    for (int i = M; i <= N; i++) {
        if (arr[i] == 0) {
            cout<<i<<"\n";
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