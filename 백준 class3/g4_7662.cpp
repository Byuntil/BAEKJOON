#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int T, k, n;
char c;

void input() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> k;
    }
}

void solution() {
    priority_queue<int, vector<int>, greater<int>> minQ;
    priority_queue<int, vector<int>, less<int>> maxQ;
    map<int, int> m;
}

void solve() {
    input();
    solution();
}

void printResult() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}