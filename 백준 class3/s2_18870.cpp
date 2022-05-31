#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<int> v1, v2;

void input() {
    cin >> N;
    int x;
    for (int i = 1; i <= N; i++) {
        cin >> x;
        v1.push_back(x);
    }
    v2 = v1;
}

void solution() {
    sort(v1.begin(), v1.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end());

    for (int i = 0; i < v2.size(); i++) {
        int num = v2[i];
        int index = lower_bound(v1.begin(), v1.end(), num) - v1.begin();
        cout << index << " ";
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