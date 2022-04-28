#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    string s;
    unordered_set<string> setA;
    cin>>s;
    for (int i = 0; i < s.length(); i++) {
        for (int k = 1; k < s.length()-i+1; k++) {
            cout<<s.substr(i,k)<<" ";
            setA.insert(s.substr(i,k));//같은 값이 있으면 푸쉬X
        }
        cout<<"\n";
    }
    cout<<setA.size();

    return 0;
}