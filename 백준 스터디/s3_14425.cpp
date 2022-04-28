#include<iostream>
#include<set>
using namespace std;

int main(){
    int N,M;
    set<string> setA;
    string s;
    int count=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>s;
        setA.insert(s);
    }
    for (int i = 0; i < M; i++) {
        cin>>s;
        if(setA.find(s)!=setA.end()){//find 했는데 s가 없다면 s.end()값과 같은 반복자 반환
            count++;
        }
    }
    cout<<count;
    return 0;
}