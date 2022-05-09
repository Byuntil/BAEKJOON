#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
int N, M;
map<string, string> account;

void input() {
    cin >> N >> M;
    string a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        account[a] = b;
    }
}

void solve() {
    input();
}

void printResult() {
    string a;
    for (int i = 0; i < M; i++) {
        cin >> a;
        cout << account[a] << "\n";
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