#include<iostream>
#include<queue>
#include<limits>
using namespace std;

/**
 * 이중 배열 2개 만들고 하나는 벽이 있는지 없는지 확인용 map배열, dist는 목표까지 가는 최소비용(거리) 확인 하는 배열
 *
 */
int N,M;
int map[100][100];
int dist[100][100];

int xArr[4] = {1,0,-1,0};
int yArr[4]={0,1,0,-1};
int BFS(int a,int b){
    queue<pair<int,int>> queue;
    queue.push({a,b});
    dist[0][0]=0;

    while(!queue.empty()){
        int x = queue.front().first;
        int y= queue.front().second;
        queue.pop();
        for(int i=0; i<4;i++){
            int nextX = x + xArr[i];
            int nextY = y + yArr[i];
            if(nextX<0||nextY<0||nextX>=M||nextY>=N)
                continue;
            if(map[nextY][nextX]==0){ //벽이 없을 때 => 기존에 있던 가중치 그대로 물려 받음
                if(dist[nextY][nextX]>dist[y][x]){ //최소를 물려 받기 위해
                    dist[nextY][nextX] = dist[y][x];
                    queue.push({nextX,nextY});
                }
            }else if(map[nextY][nextY]==1){ //벽이 있을 때 => 기존에 있던 가중치에서 +1
                if(dist[nextY][nextX]>dist[y][x]+1){//최소를 물려 받기 위해
                    dist[nextY][nextX]=dist[y][x]+1;
                    queue.push({nextX,nextY});
                }
            }
        }
        if (y == N - 1 && x == N - 1)
            return dist[N - 1][N - 1];
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>M>>N;
    for (int i = 0; i < N; i++) { //세로
        for (int j = 0; j < M; j++) {//가로
            scanf("%1d", &map[i][j]);
            dist[i][j]=numeric_limits<int>::max();
        }
    }

    cout<<BFS(0,0);
    return 0;
}