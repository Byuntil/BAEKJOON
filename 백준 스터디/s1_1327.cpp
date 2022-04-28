#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

int N,K;
int bfs(string basicString) {
    queue<pair<string,int>> q;
    map<string,bool> visited;
    q.push({basicString,0});
    visited[basicString] =true;
    string target = basicString;
    sort(target.begin(), target.end());
    while(!q.empty()){
        string s1 = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(target == s1)
            return cnt;
        for(int i=0;i<=N-K;i++){
            string x = s1.substr(i,K);
            reverse(x.begin(),x.end());
            string y = s1.substr(0,i);
            y+=x;
            y+=s1.substr(i+K);
            if(!visited[y]){
                q.push({y,cnt+1});
                visited[y] = true;
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    string s;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        char a;
        cin>>a;
        s+=a;
    }
    cout<< bfs(s);


    return 0;
}


