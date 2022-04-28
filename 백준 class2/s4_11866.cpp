#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> queue;
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n;i++){
        queue.push(i+1);
    }
    cout<<"<";
    int count = 1;
    while(!queue.empty()){
        if(count%k ==0){
            int x = queue.front();
            queue.pop();
            if(!queue.empty()){
                cout<<x<<", ";
            }else{
                cout<<x<<">";
            }
        }else{
            int x = queue.front();
            queue.pop();
            queue.push(x);
        }
        count++;
    }
    return 0;
}