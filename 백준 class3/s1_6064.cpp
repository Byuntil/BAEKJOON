#include<iostream>
#include<algorithm>

using namespace std;

int T;

void input() {
    cin >> T;
}

//최대 공약수
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//최소 공배수
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void solution() {
    int a, b, c, d;
    int j;
    for (int i = 0; i < T; i++) {
        cin >> a >> b >> c >> d;
        int l = lcm(a, b);
        for (j = c; j <= l; j += a) {
            int temp = (j % b == 0) ? b : j % b;
            if (temp == d) {
                cout << j << "\n";
                break;
            }
        }
        if (j > l) {
            cout << "-1\n";
        }
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