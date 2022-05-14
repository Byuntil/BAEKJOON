#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int N, M;
map<string, int> ma;
vector<string> v;

void input() {
    cin >> N >> M;
}

void solution() {
    string a;
    for (int i = 0; i < N + M; i++) {
        cin >> a;
        ma[a]++;
        if (ma[a] > 1) {
            v.push_back(a);
        }
    }
    sort(v.begin(), v.end());
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
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