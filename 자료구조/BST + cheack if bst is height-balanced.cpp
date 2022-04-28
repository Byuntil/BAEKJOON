#include<iostream>

using namespace std;

template<typename T, typename U>
class BinaryNode{
    template<typename T1, typename U1> friend class BinarySearchTree;
private:
    T key;
    U value;
    BinaryNode* left;
    BinaryNode* right;
public:
    BinaryNode(T key=0, U value=0, BinaryNode* left=nullptr, BinaryNode* right=nullptr){
        this->key=key;
        this->value=value;
        this->left=left;
        this->right=right;
    }
    //getter & setter
    BinaryNode<T,U>* getLeft(){return this->left;}
    BinaryNode<T,U>* getRight(){return this->right;}
    bool isLeaf(){
        return this->left == nullptr && this->right == nullptr;
    }
    bool hasTowChildren(){
        return this->left != nullptr && this->right != nullptr;
    }
    bool hasOneChildren(){
        bool hasOnlyLeft = this->left != nullptr && this->right == nullptr;
        bool hasOnlyRight = this->left == nullptr && this->right!=nullptr;
        return hasOnlyLeft || hasOnlyRight;
    }
};

template<typename T, typename U>
class BinaryTree{
protected:
    BinaryNode<T,U>* root;
    int count;
public:
    BinaryTree(){this->root = nullptr; count = 0;}
    ~BinaryTree(){removeNode(this->root);}

    void removeNode(BinaryNode<T,U>* node){
        delete(node);
    }
    bool empty(){
        return this->root == nullptr;
    }
    int getNodeCount(){
        return count;
    }

    int getHeight(BinaryNode<T,U>* node){
        if(node == nullptr) return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft>hRight)?hLeft+1:hRight+1;
    }
    bool isBalanced(BinaryNode<T,U>* node){
        int leftHeight;
        int rightHeight;

        if(node==nullptr){
            return true;
        }

        leftHeight = getHeight(node->getLeft());
        rightHeight = getHeight(node->getRight());

        if(isBalanced(node->getLeft()) &&isBalanced(node->getRight())&&(leftHeight-rightHeight)<=1&&(leftHeight-rightHeight)>=-1 ){
            return true;
        }
        return false;
    }
    int getHeight(){
        return(this->empty())?0:getHeight(this->root);
    }
    bool isBalanced(){
        return isBalanced(this->root);
    }
};

template<typename T, typename U>
class BinarySearchTree :public BinaryTree<T, U>{
private:
    BinaryNode<T,U>* search(BinaryNode<T,U>* node, T key){
        if(node == nullptr || key == node->key)
            return node;
        else if(key<node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }
    void insert(BinaryNode<T,U>* node, T key, U value){
        if(key == node->key) node->value = value;
        else if(key<node->key){
            if(node->left == nullptr){
                node->left = new BinaryNode<T,U>(key, value);
            }else{
                insert(node->left, key, value);
            }
        }else{
            if(node->right == nullptr)
                node->right = new BinaryNode<T,U>(key,value);
            else insert(node->right, key, value);
        }
    }
    BinaryNode<T,U>* remove(BinaryNode<T,U>* node, BinaryNode<T,U>* parent, T key){
        if(node==nullptr)
            return nullptr;
        if(key<node->key)
            return remove(node->left, node, key);
        else if(key>node->key)
            return remove(node->right, node, key);
        else{
            if(node->hasTowChildren()){
                BinaryNode<T,U>* succ = leftmost(node->right);
                node->key = succ->key;
                node->value = succ->value;

                succ=this->remove(node->right, node, succ->key);
                return succ;
            }else if(node->hasOneChildren()){
                BinaryNode<T,U>* child = (node->left != nullptr)?node->left:node->right;
                if(node == this->root) this->root = child;
                else{
                    if(parent->left == node)
                        parent->left = child;
                    else
                        parent->right = child;
                }
                return node;
            }else if(node->isLeaf()){
                if(node==this->root) this->root = nullptr;
                else{
                    if(parent->left == node)
                        parent->left = nullptr;
                    else
                        parent->right = nullptr;
                }
                return node;
            }
        }
    }

    BinaryNode<T,U>* leftmost(BinaryNode<T,U>* node){
        while(node->left!=nullptr)
            node=node->left;
        return node;
    }
public:
    void search(T key){
        BinaryNode<T,U>* node = search(this->root, key);
        if(node==nullptr) cout<<"out-of-key\n";
        else{
            cout<<node->value<<"\n";
        }
    }
    void insert(T key, U value){
        if(this->empty()){
            this->root = new BinaryNode<T,U>(key, value);
            this->count++;
        }else{
            insert(this->root,key,value);
            this->count++;
        }
    }
    void remove(T key){
        BinaryNode<T,U>* node = remove(this->root,nullptr, key);
        if(node==nullptr) cout<<"out-of-key\n";
        else{
            this->count--;
            delete node;
        }
    }
};

int main(){
    BinarySearchTree<int,int> bstHighBal;
    int n, value;
    string instruction;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>instruction;
        if(instruction == "insert"){
            cin>>value;
            bstHighBal.insert(value,value);
        }else if(instruction == "remove"){
            cin>>value;
            bstHighBal.remove(value);
        }
    }
    if(bstHighBal.isBalanced()){
        cout<<"Balanced\n";
    }else{
        cout<<"Unbalanced\n";
    }
    return 0;
}