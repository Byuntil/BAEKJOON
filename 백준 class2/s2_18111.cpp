#include<iostream>
#include<algorithm>

using namespace std;

int N, M, B;
int blocks[257];
int answer[2];

void input() {
    cin >> N >> M >> B;
    int total = 0;
    int x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> x;
            total += x;
            for (int k = 1; k <= x; k++) {
                blocks[k]++;
            }
        }
    }
}

void solution() {
    answer[0] = 640000000;
    for (int i = 0; i <= 256; i++) {
        int time = 0;
        int height = i;
        int inventory = B;

        for (int j = 1; j <= i; j++) {
            inventory -= N * M - blocks[j];
            time += N * M - blocks[j];
        }

        for (int j = i + 1; j <= 256; j++) {
            inventory += blocks[j];
            time += blocks[j] * 2;
        }
        if (inventory < 0)
            break;
        if (answer[0] >= time) {
            answer[0] = time;
            answer[1] = height;
        }
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << answer[0] << " " << answer[1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}