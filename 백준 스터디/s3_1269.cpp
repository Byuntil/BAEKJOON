#include<iostream>
#include<set>
using namespace std;
int main(){
    int n1,n2,x;
    set<int> set;
    cin>>n1>>n2;
    for (int i = 0; i < n1; i++) {
        cin>>x;
        set.insert(x);
    }

    for(int i=0; i<n2; i++){
        cin>>x;
        if(set.count(x)) {//있다면
            set.erase(x);
        }else{
            set.insert(x);
        }
    }
    cout << set.size();
    return 0;
}