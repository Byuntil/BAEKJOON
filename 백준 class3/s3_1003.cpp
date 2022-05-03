#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T;
vector<pair<int, int>> v;
vector<int> v2;

void input() {
    cin >> T;
    int a;
    for (int i = 0; i < T; i++) {
        cin >> a;
        v2.push_back(a);
    }
}

void solution() {
    int maxValue = -1;
    for (int i = 0; i < T; i++) {
        maxValue = max(v2[i], maxValue);
    }

    v.push_back({1, 0});
    v.push_back({0, 1});
    for (int i = 2; i <= maxValue; i++) {
        int first = v[i - 1].first + v[i - 2].first;
        int second = v[i - 1].second + v[i - 2].second;
        v.push_back({first, second});
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    for (int i = 0; i < T; i++) {
        int value = v2[i];
        cout << v[value].first << " " << v[value].second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}