#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,M;
    string s;
    unordered_map<string,int> map;
    unordered_map<int,string> map2;

    cin>>N>>M;
    for(int i=1; i<=N; i++){
        cin>>s;
        map2[i]=s;
        map[s]=i;
    }
    for(int i=0;i<M; i++){
        cin>>s;
        if('0'<=s[0]&&s[0]<='9'){
            cout<<map2[stoi(s)]<<"\n";
        }else{
            cout<<map[s]<<"\n";
        }
    }
    return 0;
}