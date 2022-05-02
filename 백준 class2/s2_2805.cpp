#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long N, M;
long long Max = -1;
vector<long long> v;

void input() {
    cin >> N >> M;
    long long a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
}

long long cutting(long long cut) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        long long cutValue = v[i] - cut;
        if (cutValue > 0) {
            sum += cutValue;
        }
    }
    return sum;
}

void solution() {
    long long left = 0;
    long long right = v[N - 1];

    while (right >= left) {
        long long mid = (right + left) / 2;
        long long x = cutting(mid);
        if (x >= M) {
            left = mid + 1;
            if (mid > Max)
                Max = mid;
        } else {
            right = mid - 1;
        }
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << Max;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}