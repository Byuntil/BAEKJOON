#include <iostream>
#include<queue>
#include<algorithm>

using namespace std;

int countHeight;
vector<int> arr[500001];
bool visited[500001];

void dfs(int i, int depth){
    if(i!=1&&arr[i].size()==1){
        if(depth%2==1)
            countHeight++;
        return;
    }
    for(int j=0; j<arr[i].size(); j++){
        if(!visited[i]){
            visited[i] = true;
            dfs(arr[i][j], depth+1);
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,a,b;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1,0);
    if(countHeight%2==1){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}
