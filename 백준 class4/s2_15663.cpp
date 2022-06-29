#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int answer[10];
int nNum[10];
bool visit[10];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> nNum[i];
    }
    sort(nNum, nNum + N);
}

void e(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }
    int xx = 0;
    for (int i = 0; i < N; i++) {
        if (!visit[i] && nNum[i] != xx) {
            answer[cnt] = nNum[i];
            xx = answer[cnt];
            visit[i] = true;
            e(cnt + 1);
            visit[i] = false;
        }
    }
}

void solution() {
    e(0);

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