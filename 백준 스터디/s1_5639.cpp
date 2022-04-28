#include<iostream>
#include<cstdio>

using namespace std;

class BinaryNode{
    friend class BinaryTree;
private:
    int key;
    int value;
    BinaryNode* left;
    BinaryNode* right;
public:
    BinaryNode(int key=0, int value=0, BinaryNode* left=nullptr, BinaryNode* right=nullptr) {
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
    }
    BinaryNode* getLeft(){
        return this->left;
    }
    BinaryNode* getRight(){
        return this->right;
    }
    int getValue(){
        return this->value;
    }
};

int answer[1024];

class BinaryTree{
private:
    BinaryNode* root;
    int count;
public:
    BinaryTree(){this->root = nullptr; count=0;}
    ~BinaryTree(){removeNode(this->root);}

    void removeNode(BinaryNode* node){
        delete(node);
    }
    void insert(BinaryNode* node, int key, int value){
        if(key == node->key) node->value = value;
        else if(key<node->key){
            if(node->left == nullptr){
                node->left = new BinaryNode(key, value);
            }else{
                insert(node->left, key, value);
            }
        }else{
            if(node->right == nullptr)
                node->right = new BinaryNode(key,value);
            else insert(node->right, key, value);
        }
    }
    bool empty(){
        return this->root == nullptr;
    }
    void insert(int key, int value){
        if(this->empty()){
            this->root = new BinaryNode(key, value);
        }else{
            insert(this->root,key,value);
            count++;
        }
    }
    void postOrder(BinaryNode* node){
        if(node!=nullptr){
            postOrder(node->getLeft());
            postOrder(node->getRight());
            cout<<node->getValue()<<"\n";
        }
    }
    void postOrder(){
        postOrder(this->root);
    }
};
int main(){
    int n;
    BinaryTree binaryTree;
    while(scanf("%d", &n)!=-1){
        binaryTree.insert(n,n);
    }
    binaryTree.postOrder();
    return 0;
}