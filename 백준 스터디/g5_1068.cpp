#include<iostream>
#include<vector>

using namespace std;

vector<int> node[55];
int deleteNode;

int findLeaf(int p){
    int leafNodeNum = 0;

    for (int i : node[p]) {
        if(i==deleteNode)
            continue;
        leafNodeNum += findLeaf(i);
    }
    if(leafNodeNum){
        return leafNodeNum;
    }else{
        return 1;
    }
}

int main(){

    int n,addNode;
    int rootNode;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>addNode;
        if(addNode==-1){
            rootNode = i;
        }else{
            node[addNode].push_back(i);
        }
    }
    cin>>deleteNode;
    if(rootNode!=deleteNode){
        cout<<findLeaf(rootNode);
    }else{
        cout<<"0";
    }

    return 0;
}