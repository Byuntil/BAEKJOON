#include<iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int j=0; j<T; j++){
        int N, M,a,b;
        cin>>N>>M;
        for(int i=0; i<M;i++){
            cin>>a>>b;
        }
        cout<<N-1<<"\n";
    }

    return 0;
}