#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,string> u, pair<int,string> v){
    return u.first < v.first;
}
int main(){
    int n, a;
    string s;
    cin>>n;
    vector<pair<int,string>> vector;

    for(int i=0; i<n; i++){
        cin>>a>>s;
        vector.emplace_back(a,s);
    }
    stable_sort(vector.begin(),vector.end(), cmp);
    for(int i=0; i<n; i++){
        cout<<vector[i].first<<" "<<vector[i].second<<"\n";
    }
    return 0;
}