#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<pair<int,int>> vector;
    int n, x, y;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        vector.emplace_back(x,y);
    }
    sort(vector.begin(), vector.end());

    for(int i=0; i<n; i++){
        cout<<vector.at(i).first<<" "<<vector.at(i).second<<"\n";
    }
    return 0;
}