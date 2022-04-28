#include <iostream>
#include <queue>
#include <vector>
#include<limits>
#include <algorithm>

using namespace std;
int N, M;
int minValue[1001]; //거리값
vector<pair<int,int>> vertex[1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a,b,c; //출발 번호, 도착 번호, 비용
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq; //거리값, 도시 번호
    cin>>N>>M;


    for (int i = 0; i < M; i++) {
        cin>>a>>b>>c;
        vertex[a].emplace_back(b,c);
    }
    for (int i = 1; i <= N; i++) {
        minValue[i] = numeric_limits<int>::max();
    }

    int startPoint, endPoint;
    cin>>startPoint>>endPoint;//구하고자 하는 구간 출발 점 , 도착점

    minValue[startPoint] = 0;
    pq.push({0,startPoint});

    while (!pq.empty()) {
        int distValue = pq.top().first;
        int cityNumber = pq.top().second;
        pq.pop();

        if(minValue[cityNumber]<distValue)
            continue;
        //연결된 도시들 조사
        for (int i = 0; i < vertex[cityNumber].size(); i++) {
            int nextCityDistValue = vertex[cityNumber][i].second;
            int nextCityNumber = vertex[cityNumber][i].first;

            if(minValue[nextCityNumber] > distValue + nextCityDistValue){
                minValue[nextCityNumber] = distValue+nextCityDistValue;
                pq.push({minValue[nextCityNumber],nextCityNumber});
            }
        }

    }

    cout<<minValue[endPoint];
    return 0;
}