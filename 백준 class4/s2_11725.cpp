#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<int> tree[100005];
int answer[100005] = {1};

void input() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

void dfs(int start) {
    for (int i = 0; i < tree[start].size(); i++) {
        int k = tree[start][i];

        if (answer[k] == 0) {
            answer[k] = start;
            dfs(k);
        }
    }
    return;
}

void solution() {
    dfs(1);
}

void solve() {
    input();
    solution();
}

void printResult() {
    for (int i = 2; i <= N; i++) {
        cout << answer[i] << "\n";
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