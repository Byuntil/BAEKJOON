#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
bool visit[9];
vector<int> nNum;
vector<int> answer;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        nNum.push_back(a);
    }
    sort(nNum.begin(), nNum.end());
}

void c(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            visit[i] = true;
            answer.push_back(nNum[i]);
            c(cnt + 1);
            answer.pop_back();
            visit[i] = false;
        }
    }
}

void solution() {
    c(0);

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