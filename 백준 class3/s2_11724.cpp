#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
vector<int> a[1001];
int checked[1001];
int component;

void input() {
    cin >> N >> M;
    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        a[v].push_back(u);
        a[u].push_back(v);
    }
}

void dfs(int n) {
    checked[n] = true;
    for (int i = 0; i < a[n].size(); i++) {
        int nextNode = a[n][i];
        if (!checked[nextNode]) {
            dfs(nextNode);
        }
    }
}

void solution() {
    for (int i = 1; i <= N; i++) {
        if (!checked[i]) {
            dfs(i);
            component++;
        }
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << component;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}