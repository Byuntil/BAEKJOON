#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int testNum, N, M;
int countVal;

void solution() {
    int ipt;
    queue <pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        cin >> ipt;
        pq.push(ipt);
        q.push({i, ipt});
    }
    while (!q.empty()) {
        int index = q.front().first;
        int iptValue = q.front().second;
        q.pop();
        if (pq.top() == iptValue) {
            pq.pop();
            countVal++;
            if (index == M) {
                cout << countVal << "\n";
                break;
            }
        } else {
            q.push({index, iptValue});
        }
    }
}

void input() {
    cin >> testNum;
    for (int i = 0; i < testNum; i++) {
        cin >> N >> M;
        countVal = 0;
        solution();
    }
}

void solve() {
    input();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}