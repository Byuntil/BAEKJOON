#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N,n;
    long arr[100000];
    long arr2[100000];
    long sum=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    /*
    for(int i=0;i<N-1;i++){
        for(int j=i+1; j<N;j++){
            sum += vector[i]*vector[j];
        }
    }
     */
    arr2[0] = arr[N-1];
    for(int i=1;i<N;i++){
        arr2[i] = arr2[i-1] + arr[N-i-1];
    }
    for(int i=1 ;i<N;i++){
        sum+=arr[N-i-1]*arr2[i-1];
    }
    cout<<sum;
    return 0;
}