#include<iostream>
#include<algorithm>
#include<deque>


using namespace std;
int T;
string funt, arr;
int n;
bool order, err;

void input() {
    cin >> T;
}

void solution() {
    int j;
    for (int i = 0; i < T; i++) {
        err = false;
        order = true;
        deque<int> de;
        cin >> funt >> n >> arr;
        j = 1;
        while (arr[j] != '\0') {
            int x = 0;
            while (arr[j] >= '0' && arr[j] <= '9') {
                x *= 10;
                x += arr[j] - '0';
                j++;
            }
            if (x != 0) {
                de.push_back(x);
            }
            j++;
        }
        for (int j = 0; j < funt.size(); j++) {
            char t = funt[j];
            if (t == 'R') {
                order = !order;
            } else if (t == 'D') {
                if (de.empty()) {
                    cout << "error\n";
                    err = true;
                    break;
                }
                if (order) {
                    de.pop_front();
                } else {
                    de.pop_back();
                }
            }
        }
        if (!err) {
            cout << "[";
        }
        while (!de.empty()) {
            if (order) {
                int c = de.front();
                de.pop_front();
                cout << c;
            } else {
                int c = de.back();
                de.pop_back();
                cout << c;
            }
            if (!de.empty()) {
                cout << ",";
            }
        }
        if (!err) {
            cout << "]\n";
        }
    }
}

void solve() {
    input();
    solution();
}

void printResult() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}