#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    else{
        return gcd(b,a%b);
    }
}
int main(){
    int n1, n2;
    cin>>n1>>n2;
    int num = gcd(n1,n2);
    cout<<num<<"\n"<<n1*n2/num;
    return 0;
}