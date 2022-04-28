#include<iostream>
using namespace std;

int main(){
    int n, a, s=0;
    cin>>n;
    int j;
    for(int i=0; i<n; i++){
        cin>>a;
        for(j=2; j<a; j++){
            if(a%j==0) break;
        }
        if(j==a)
            s++;
    }
    cout<<s;
    return 0;
}