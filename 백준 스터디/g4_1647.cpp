#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//최대 가중치로 연결 되어있는 도시를 빼면 됨
int N, M;
vector<pair<int,pair<int,int>>> edges; //<가중치,<정점,정점>>
int parent[100001];

int find(int x){
    if(x==parent[x])
        return x;
    else{
        return parent[x]=find(parent[x]);
    }
}
void Union(int x,int y){
    int px = find(x);
    int py = find(y);
    if(px==py)
        return;
    else{
        parent[y] = px;
    }
}
int main(){
    cin>>N>>M;
    int a,b,c;
    //1. 최소 힙에 추가
    for (int i = 0; i < M; i++) {
        cin>>a>>b>>c;
        edges.push_back({c,{a,b}});
    }

    //가중치를 오름차순으로 정렬
    sort(edges.begin(),edges.end());

    //2. 유니온 파인드 자료 구조 시작
    //make-set
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    int maxCost=0;
    int result=0;
    //union-find
    for (auto & edge : edges) {
        int cost = edge.first;
        int x = edge.second.first;
        int y = edge.second.second;

        if(find(x) != find(y)) {
            maxCost = max(maxCost, cost);
            result += cost;
            Union(x,y);
        }
    }

    cout<<result-maxCost;
    return 0;
}