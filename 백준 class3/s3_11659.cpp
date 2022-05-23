#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


/*누적합 처음부터 순서대로 0~1까지의 합 0~2까지의 합 ... 구하고
a~b의 합을 구하라고 하면 0~b의 합 - 0~a의 합*/


int N, M;
int arr[100001];
int su[100001];
vector <pair<int, int>> range;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        su[i] = su[i - 1] + arr[i];
    }
    int I, J;
    for (int i = 0; i < M; i++) {
        cin >> I >> J;
        range.push_back({I, J});
    }
}

void solution() {
    for (int i = 0; i < M; i++) {
        int start = range[i].first;
        int end = range[i].second;
        cout << su[end] - su[start - 1] << "\n";
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
