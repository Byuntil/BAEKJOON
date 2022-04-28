#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

priority_queue<int, vector<int>,greater<int>> q1;
priority_queue<int> q2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==0){
            if(q1.empty()&&q2.empty()){
                cout<<"0\n";
            }else{
                if(q1.empty()){
                    cout<<q2.top()<<"\n";
                    q2.pop();
                }else if(q2.empty()){
                    cout<<q1.top()<<"\n";
                    q1.pop();
                }else{
                    if(q1.top()<-q2.top()){
                        cout<<q1.top()<<"\n";
                        q1.pop();
                    }else{
                        cout<<q2.top()<<"\n";
                        q2.pop();
                    }
                }
            }
        }else if(x>0){
            q1.push(x);
        }else{
            q2.push(x);
        }
    }
    return 0;
}