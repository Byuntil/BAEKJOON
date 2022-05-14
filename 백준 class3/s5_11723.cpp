#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int M;
int arr[21];

void input() {
    cin >> M;
}

void solution() {
    int num;
    string command;
    for (int i = 0; i < M; i++) {
        cin >> command;
        if (command == "add") {
            cin >> num;
            if (arr[num] == 0) {
                arr[num] = 1;
            }
        } else if (command == "check") {
            cin >> num;
            if (arr[num] == 0) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
        } else if (command == "remove") {
            cin >> num;
            if (arr[num] == 1) {
                arr[num] = 0;
            }
        } else if (command == "toggle") {
            cin >> num;
            if (arr[num] == 0) {
                arr[num] = 1;
            } else {
                arr[num] = 0;
            }
        } else if (command == "all") {
            for (int j = 1; j <= 20; j++) {
                arr[j] = 1;
            }
        } else if (command == "empty") {
            memset(arr, 0, sizeof(arr));
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