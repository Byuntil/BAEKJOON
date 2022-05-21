#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int computerNum, connectedNum, cnt;
vector<int> arr[101];
bool check[101];

void input() {
    cin >> computerNum;
    cin >> connectedNum;
}

void dfs(int x) {
    check[x] = true;
    for (int i = 0; i < arr[x].size(); i++) {
        int y = arr[x][i];
        if (!check[y]) {
            dfs(y);
            cnt++;
        }
    }
}

void solution() {
    int a, b;
    for (int i = 1; i <= connectedNum; i++) {
        cin >> a >> b;
        arr[b].push_back(a);
        arr[a].push_back(b);
    }
    dfs(1);
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}