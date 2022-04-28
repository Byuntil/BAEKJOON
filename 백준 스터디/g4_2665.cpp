#include<iostream>
#include<queue>
#include<limits>

using namespace std;
// 0은 검은방 / 1은 흰방
int N;
int map[55][55];
int dist[55][55];

int xArr[4] = {1,0,-1,0};
int yArr[4]={0,1,0,-1};

int BFS(int a,int b){
    queue<pair<int,int>> queue;
    queue.push({a,b});
    dist[0][0]=0;

    while(!queue.empty()){
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + xArr[i];
            int nextY = y + yArr[i];
            if(x<0||y<0||nextX>=N||nextY>=N)
                continue;
            if(map[nextY][nextX]==0) { //검은 방일 때
                if(dist[nextY][nextX]>dist[y][x]+1) {
                    dist[nextY][nextX]=dist[y][x]+1;
                    queue.push({nextX,nextY});
                }
            }else if(map[nextY][nextX]==1){ //흰 방일 때
                if(dist[nextY][nextX]>dist[y][x]) {
                    dist[nextY][nextX]=dist[y][x];
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
    cin>>N;
    for (int i = 0; i < N; i++) {
        for(int j=0;j<N; j++){
            scanf("%1d", &map[i][j]);
            dist[i][j] = numeric_limits<int>::max();
        }
    }

    cout<<BFS(0,0);
    return 0;
}