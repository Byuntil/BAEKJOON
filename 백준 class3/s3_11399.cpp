#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int result;
vector<int> v;

void input() {
    cin >> N;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }
}

void solution() {
    sort(v.begin(), v.end());
    int w = 0;
    for (int i = 0; i < v.size(); i++) {
        result += v[i] + w;
        w += v[i];
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}