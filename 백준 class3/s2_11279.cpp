#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N;
priority_queue<int, vector<int>> pq;

void input() {
    cin >> N;
}

void solution() {
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) {
            if (pq.size()) {
                cout << pq.top() << "\n";
                pq.pop();
            } else {
                cout << 0 << "\n";
            }
        } else {
            pq.push(x);
        }
    }
}

void solve() {
    input();
    solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}