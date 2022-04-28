#include<iostream>
#include<vector>
#include <cstring>


using namespace std;

vector<pair<int, int>> node[10002];
bool visited[10002] = {false,};
int endPoint = 0;
int result = 0;
void dfs(int p,int len){
    if(visited[p])
        return;
    visited[p] = true;
    if(result<len){
        result = len;
        endPoint = p;
    }

    for (auto & i : node[p]) {
        dfs(i.first,len + i.second);//가중치를 계속 더해감
    }
}
int main(){
    int n;
    int currentNode, linkedNode,num;
    cin>>n;
    for (int i = 0; i < n - 1; i++) {
        cin>>currentNode;
        cin>>linkedNode;
        cin>>num;
        node[currentNode].emplace_back(linkedNode,num);//{node,가중치}
        node[linkedNode].emplace_back(currentNode,num);
    }
    dfs(1, 0);//endPoint 구하는 용
    memset(visited, false,sizeof(visited));
    result = 0;
    dfs(endPoint,0);
    cout<<result;
    return 0;
}