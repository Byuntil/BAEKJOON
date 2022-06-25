#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//조합
int N, M;
string arr[105][105];

void input() {
    cin >> N >> M;
}

string add(string num1, string num2) {
    string num = "";
    int sum = 0;
    int size = max(num1.size(), num2.size());
    for (int i = 0; i < size || sum; i++) {
        if (num1.size() > i) {
            sum += num1[i] - '0';
        }
        if (num2.size() > i) {
            sum += num2[i] - '0';
        }
        num += sum % 10 + '0';
        sum /= 10;
    }
    return num;
}

//nCm = n-1Cm-1 + n-1Cm
string combine(int n, int m) {
    if (n == m || m == 0) {
        return "1";
    }

    string &ans = arr[n][m];

    if (ans != "") {
        return ans;
    }
    ans = add(combine(n - 1, m - 1), combine(n - 1, m));

    return ans;
}

void solution() {
    combine(N, M);
}

void solve() {
    input();
    solution();
}

void printResult() {
    for (int i = arr[N][M].size() - 1; i >= 0; i--) {
        cout << arr[N][M][i];
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