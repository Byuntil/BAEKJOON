#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M, V;
vector<int> v[1001];
bool visit[1001];

void input() {
    cin >> N >> M >> V;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    sort(v[a].begin(), v[a].end());
    sort(v[b].begin(), v[b].end());
}

void DFS(int value) {
    cout << value << " ";
    visit[value] = true;
    for (int i = 0; i < v[value].size(); i++) {
        int next = v[value][i];
        if (!visit[next]) {
            visit[next] = true;
            DFS(next);
        }
    }
}

void BFS(int value) {
    queue<int> q;
    q.push(value);
    visit[value] = true;
    cout << value << " ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < v[current].size(); i++) {
            int next = v[current][i];
            if (!visit[next]) {
                visit[next] = true;
                q.push(next);
                cout << next << " ";
            }
        }
    }
}

void solution() {
    DFS(V);
    cout << "\n";
    memset(visit, false, sizeof(visit));
    BFS(V);
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