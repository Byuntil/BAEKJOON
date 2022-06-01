#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string Input;
int result;

void input() {
    cin >> Input;
}

void solution() {
    bool isMinus = false;
    string num;
    for (int i = 0; i <= Input.size(); i++) {
        if (Input[i] == '-' || Input[i] == '+' || i == Input.size()) {
            if (isMinus) {
                result -= stoi(num);
                num = "";
            } else {
                result += stoi(num);
                num = "";
            }
        } else {
            num += Input[i];
        }
        if (Input[i] == '-') {
            isMinus = true;
        }
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}