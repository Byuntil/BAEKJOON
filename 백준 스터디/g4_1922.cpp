#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;//컴퓨터 수, 간선의 수
int result;
vector<pair<int,pair<int,int>>> edges; //<가중치,<정점,정점>>
int parent[1001];

void input() {
    int a,b,c;
    cin>>N;
    cin>>M;
    for (int i = 0; i < M; i++) {
        cin>>a>>b>>c;
        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

int find(int x){
    if (x == parent[x]) {
        return x;
    }else{
        return parent[x] = find(parent[x]);
    }
}

void Union(int x, int y){
    int px = find(x);
    int py = find(y);
    if (px == py) {
        return;
    }else{
        parent[py] = px;
    }
}
void solution() {
    for (auto & edge  : edges) {
        int cost = edge.first;
        int x = edge.second.first;
        int y = edge.second.second;
        if (find(x) != find(y)) {
            result += cost;
            Union(x,y);
        }
    }
}

void solve() {
    input();
    solution();
}
void printResult() {
    cout<<result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}


