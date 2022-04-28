#include<iostream>
#include<algorithm>
#include<queue>
#include<limits>

using namespace std;

int V, E, K;
int minValue[20001]; //각 정점의 거리값
vector<pair<int,int>> vertex[20001]; //[연결 하는 노드]<연결된 노드, 가중치>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /**
    *우선 순위 큐(최소합) first : 거리값 / second : 정점 번호 => 이거 순서 바뀌면 시간 초과 남
    *정렬이 first 값이 작은 -> 큰 순, 같으면 second 값이 작은 -> 큰순 우선 순위 큐 정렬됨
    */
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    int a,b,c;
    cin>>V>>E>>K;
    for (int i = 0; i < E; i++) {
        cin>>a>>b>>c;
        vertex[a].emplace_back(b,c);
    }

    //각 정점의 거리값 최대로 초기화
    for(int i=1; i<=V; i++){
        minValue[i] = numeric_limits<int>::max();
    }

    //시작 정점은 0으로
    minValue[K]=0;

    //모든 거리 값을 최소 힙에 추가
    pq.push({0,K});
    while(!pq.empty()){
        int distValue = pq.top().first;
        int nodeNumber = pq.top().second;

        pq.pop();

        //이미 해당 노드의 가중 값이 이미 작으면 루프 돌 필요X
        if(minValue[nodeNumber]<distValue)
            continue;

        //노드와 연결된 노드들 조회
        for (int i = 0; i < vertex[nodeNumber].size(); i++) {
            int nextNodeNumber = vertex[nodeNumber][i].first;
            int nextNodeLineWeight = vertex[nodeNumber][i].second;

            if(minValue[nextNodeNumber] > distValue+nextNodeLineWeight){
                minValue[nextNodeNumber] = distValue+nextNodeLineWeight;
                pq.push({minValue[nextNodeNumber],nextNodeNumber});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if(minValue[i]==numeric_limits<int>::max()){
            cout<<"INF"<<"\n";
        }else{
            cout<<minValue[i]<<"\n";
        }
    }
    return 0;
}