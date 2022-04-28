#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<long long, vector<long long>,greater<long long>> q1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int m,x;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        q1.push(x);
    }
    for(int i=0;i<m;i++){
        long long x1,x2,x3;
        x1 = q1.top();
        q1.pop();
        x2 = q1.top();
        q1.pop();
        x3 = x1+x2;

        q1.push(x3);
        q1.push(x3);
    }
    long long result=0;
    for(int i=0; i<n;i++){
        result += q1.top();
        q1.pop();
    }
    cout<<result;
    return 0;
}