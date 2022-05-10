#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v, b;
int N, I;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> I;
        v.push_back(I);
        b.push_back(I);
    }
}

void solution() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

void solve() {
    input();
    solution();
}

void printResult() {
    for (int i = 0; i < N; i++) {
        cout << lower_bound(v.begin(), v.end(), b[i]) - v.begin();
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