#include <iostream>
using namespace std;

int main(){
    int T, H, W, N;
    cin>>T;
    for(int i=0; i<T; i++){
        int h=1, w=1;
        cin>>H>>W>>N;
        for(int j=0; j<N-1; j++){
            if(h<H){
                h++;
            }else{
                h=1;
                if(w<W){
                    w++;
                }else{
                    w=1;
                }
            }
        }
        if(w<10){
            cout<<h<<"0"<<w<<"\n";
        }else{
            cout<<h<<w<<"\n";
        }
    }
    return 0;
}