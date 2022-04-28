#include<iostream>
using namespace std;

int main(){
    int N, K;
    cin>>N>>K;
    if(0<=K&&K<=N){
        int n=1, k=1, s=1;
        for(int i= N; i>0; i--){
            n *= i;
        }
        for(int i=K; i>0; i--){
            k *= i;
        }
        for(int i=N-K; i>0; i--){
            s *= i;
        }
        cout<<n/(k*s);
    }else{
        cout<<"0";
    }
    return 0;
}