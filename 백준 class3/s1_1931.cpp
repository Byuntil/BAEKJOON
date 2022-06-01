#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, cnt;
vector<pair<int, int>> v;

void input() {
    cin >> N;
    int start, end;
    for (int i = 0; i < N; i++) {
        cin >> start >> end;
        v.push_back({end, start});
    }
    sort(v.begin(), v.end());
}

void solution() {
    int time = v[0].first;
    cnt = 1;
    for (int i = 1; i < N; i++) {
        if (time <= v[i].second) {
            cnt++;
            time = v[i].first;
        }
    }
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