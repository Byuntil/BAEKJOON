#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int numA,numB, k,count=0;
    vector<int> setA;
    set<int> setB, setC;
    cin>>numA>>numB;
    for (int i = 0; i < numA; i++) {
        cin>>k;
        setA.push_back(k);
    }
    for (int i = 0; i < numB; i++) {
        cin>>k;
        setB.insert(k);
    }

    for(int i=0; i<numA; i++){
        if(setB.find(setA[i])==setB.end()){
            setC.insert(setA[i]);
            count++;
        }
    }

    cout<<count<<"\n";
    set<int>::iterator iter;
    for(iter = setC.begin(); iter != setC.end(); iter++){
        cout << *iter << " " ;
    }

    return 0;
}