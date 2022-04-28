#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

int N, E;
int v1,v2;
int oneToV1, oneToV2, v1ToV2, v1ToN, v2ToN;
int result = numeric_limits<int>::max();
int minValue[801];
vector<pair<int,int>> vertex[801];
void input() {
    cin>>N>>E;
    int a,b,c;
    for (int i = 0; i < E; i++) {
        cin>>a>>b>>c;
        vertex[a].emplace_back(b,c);
        vertex[b].emplace_back(a,c); //양방향이기 때문에 추가
    }
    cin>>v1>>v2;
}

void dx(int start){
    for (int i = 1; i <= N; i++) {
        minValue[i] = numeric_limits<int>::max();
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    minValue[start]=0;
    pq.push({0,start});
    while (!pq.empty()) {
        int distValue = pq.top().first;
        int nodeNumber = pq.top().second;

        pq.pop();

        if(minValue[nodeNumber]<distValue)
            continue;

        for (auto & i : vertex[nodeNumber]) {
            int nextNodeNumber = i.first;
            int nextNodeLineWeight = i.second;
            if(minValue[nextNodeNumber] > distValue+nextNodeLineWeight){
                minValue[nextNodeNumber] = distValue+nextNodeLineWeight;
                pq.push({minValue[nextNodeNumber],nextNodeNumber});
            }
        }
    }
}

 //(1->v1)->(v1->v2)->(v2->N)
 //(1->v2)->(v1->v2)->(v1->N)
void solution() {

    dx(1);
    oneToV1 = minValue[v1];
    oneToV2 = minValue[v2];

    dx(v1);
    v1ToV2 = minValue[v2];
    v1ToN = minValue[N];

    dx(v2);
    v2ToN = minValue[N];

    int route1 = oneToV1 + v1ToV2 + v2ToN;
    int route2 = oneToV2 + v1ToV2 + v1ToN;
    result = min(result,route1);
    result = min(result,route2);
}

void solve() {
    input();
    solution();
}

void printResult() {
    if(result == numeric_limits<int>::max()||v1ToV2== numeric_limits<int>::max())
        cout<<-1;
    else{
        cout<<result;
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