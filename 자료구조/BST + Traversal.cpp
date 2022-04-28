#include<iostream>
#include<queue>
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
    U getValue(){return this->value;}
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
    void preOrder(BinaryNode<T,U>* node);
    void inOrder(BinaryNode<T,U>* node);
    void postOrder(BinaryNode<T,U>* node);
    void levelOrder(BinaryNode<T,U>* node);

    void preOrder(){
        cout<<"preorder: ";
        preOrder(this->root);
        cout<<"\n";
    }
    void inOrder(){
        cout<<"inorder: ";
        inOrder(this->root);
        cout<<"\n";
    }
    void postOrder(){
        cout<<"postorder: ";
        postOrder(this->root);
        cout<<"\n";
    }
    void levelOrder(){
        queue<BinaryNode<T, U>*> Q;
        Q.push(this->root);
        cout<<"levelorder: ";
        while(!Q.empty()){
            BinaryNode<T, U>* cur_node = Q.front();
            Q.pop();
            if(cur_node !=nullptr){
                cout<<cur_node->getValue()<<" ";
                Q.push(cur_node->getLeft());
                Q.push(cur_node->getRight());
            }
        }
        cout<<"\n";
    }
};

template<typename T, typename U>
void BinaryTree<T, U>::preOrder(BinaryNode<T, U> *node) {
    if(node!=nullptr){
        cout<<node->getValue()<<" ";
        preOrder(node->getLeft());
        preOrder(node->getRight());
    }
}

template<typename T, typename U>
void BinaryTree<T, U>::inOrder(BinaryNode<T, U> *node) {
    if(node!=nullptr) {
        inOrder(node->getLeft());
        cout<<node->getValue()<<" ";
        inOrder(node->getRight());
    }
}

template<typename T, typename U>
void BinaryTree<T, U>::postOrder(BinaryNode<T, U> *node) {
    if(node!=nullptr){
        postOrder(node->getLeft());
        postOrder(node->getRight());
        cout<<node->getValue()<<" ";
    }
}


template<typename T, typename U>
class BinarySearchTree :public BinaryTree<T, U>{
private:
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
    BinarySearchTree<int,int> bstTraversal;
    int n, number;
    string instruction;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>instruction;
        if(instruction == "insert"){
            cin>>number;
            bstTraversal.insert(number,number);
        }else if(instruction == "remove"){
            cin>>number;
            bstTraversal.remove(number);
        }
    }

    bstTraversal.preOrder();
    bstTraversal.inOrder();
    bstTraversal.postOrder();
    bstTraversal.levelOrder();

    return 0;
}