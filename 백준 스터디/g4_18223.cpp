#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

int V, E;
int P;
int a,b;
bool isSave = false;
int minValue[5001];
vector<pair<int,int>> vertex[5001];
void input() {
    cin>>V>>E>>P;
    int a,b,c;
    for (int i = 0; i < E; i++) {
        cin>>a>>b>>c;
        vertex[a].emplace_back(b,c);
        vertex[b].emplace_back(a,c); //양방향이기 때문에 추가
    }
}

void dx(int start){
    for (int i = 1; i <= V; i++) {
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

//a : 1->마산
//b : 1->건우->마산
//a==b ? SAVE HIM : GOOD BYE
void solution() {
    //a
    dx(1);
    a = minValue[V];

    //b
    b += minValue[P];
    dx(P);
    b += minValue[V];
}

void solve() {
    input();
    solution();
}

void printResult() {
    if(a==b)
        cout<<"SAVE HIM";
    else
        cout<<"GOOD BYE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}