#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits>

using namespace std;

int N, M, K, X;
vector<pair<int,int>> vec[300001];
int dist[300001];

void input() {
    cin>>N>>M>>K>>X;
    int a,b;
    for (int i =0; i < M; i++) {
        cin>>a>>b;
        vec[a].emplace_back(1,b);
    }
    for (int i = 1; i <= N; i++) {
        dist[i]=numeric_limits<int>::max();
    }
}

void se(int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,start});
    dist[start]=0;

    while (!pq.empty()) {
        int distValue = pq.top().first;
        int nodeNumber = pq.top().second;
        pq.pop();
        if (dist[nodeNumber] < distValue) {
            continue;
        }
        for (auto & i : vec[nodeNumber]) {
            int nextDistValue = i.first;
            int nextNode = i.second;
            if(distValue + nextDistValue < dist[nextNode]) {
                dist[nextNode] = distValue + nextDistValue;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

void solution() {
    se(X);
    int flag = 0;
    for(int i = 1; i <= N;i++) {
        if(dist[i] == K) {
            cout << i << '\n';
            flag = 1;
        }
    }
    if(!flag) cout << -1 << '\n';
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