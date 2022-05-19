#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int T;

void input() {
    cin >> T;
}

void solution() {
    int n;
    string clothes, clothesType;
    for (int i = 0; i < T; i++) {
        map<string, int> ma;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> clothes >> clothesType;
            if (ma.find(clothesType) == ma.end()) {
                ma.insert({clothesType, 1});
            } else {
                ma[clothesType]++;
            }
        }
        int ans = 1;
        for (auto a: ma) {
            ans *= (a.second + 1);
        }
        ans -= 1;
        cout << ans << "\n";
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