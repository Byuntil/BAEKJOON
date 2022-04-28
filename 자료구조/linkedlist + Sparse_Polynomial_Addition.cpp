#include<iostream>
using namespace std;

class Polynomial{
private:
    double coeff; // 계수
    int degree;   // 차수
public:
    Polynomial(double coeff = 0.0, int degree = 0){
        this->coeff = coeff;
        this->degree = degree;
    }

    double getCoeff() const{ return this->coeff; }
    int getDegree() const{return this->degree;}
};
//LinkedList
template<typename T>
class Node{
private:
    T data;
    Node* link;
public:
    Node(T val=0) : data(val), link(nullptr) {}
    Node* getLink(){return this->link;}
    void setLink(Node* next){this->link = next;}
    bool hasData(T val){return this->data==val;}
    void setData(T settingData){this->data = settingData;}
    T getData(){return this->data;}
};

template<typename U>
class LinkedList{
private:
    Node<U> head;
    int cnt;

    Node<U>* getHead(){return head.getLink();}
    Node<U>* getNode(int pos){
        Node<U>* p = &head;
        for(int i=-1;i<pos;i++){
            if(p==nullptr)break;
            p=p->getLink();
        }
        return p;
    }
public:
    LinkedList(){
        this->cnt = 0;
    }
    bool empty(){return this->getHead()==nullptr;}
    int size(){return this->cnt;}
    void insert(int pos, U data);
    void remove(int pos);
    int find(int query);
    void replace(int pos, U data);
    void display();
    U get(int pos){
        Node<U>* node = getNode(pos);
        return node->getData();
    }
    ~LinkedList<U>(){
        while(!this->empty()){
            this->remove(0);
        }
    }
    void sorted_insert(int co, int de);
    LinkedList<U> operator+(LinkedList<U>& listB){
        LinkedList<U> result;
        int count=0;
        Node<U>* pA = getHead();
        Node<U>* pB = listB.getHead();

        while(pA!=nullptr&&pB!=nullptr){
            U degA = pA->getData();
            U degB = pB->getData();
            if(degA.getDegree()==degB.getDegree()){
                Polynomial p(degA.getCoeff()+degB.getCoeff(), degA.getDegree());
                result.insert(count++,p);
                pA = pA->getLink();
                pB = pB->getLink();
            }else if(degA.getDegree()>degB.getDegree()){
                Polynomial p(degA.getCoeff(), degA.getDegree());
                result.insert(count++,p);
                pA = pA->getLink();
            }else{
                Polynomial p(degB.getCoeff(), degB.getDegree());
                result.insert(count++,p);
                pB = pB->getLink();
            }
        }

        for(;pA!=nullptr;pA=pA->getLink()){
            U degA = pA->getData();
            Polynomial p(degA.getCoeff(), degA.getDegree());
            result.insert(count++,p);
        }
        for(;pB!=nullptr;pB=pB->getLink()){
            U degB = pB->getData();
            Polynomial p(degB.getCoeff(), degB.getDegree());
            result.insert(count++,p);
        }
        return result;
    }
};

template<typename U>
void LinkedList<U>::insert(int pos, U data) {
    if(!(pos>=0&&pos<=size()))
        cout<<"error\n";
    Node<U>* prev = this->getNode(pos-1);
    if(prev!=nullptr){
        Node<U>* p = new Node<U>(data);
        p->setLink(prev->getLink());
        prev->setLink(p);
        this->cnt++;
    }
}

template<typename U>
void LinkedList<U>::remove(int pos) {
    if(this->empty())
        cout<<"error\n";
    Node<U>* prev = this->getNode(pos-1);
    if(prev!=nullptr){
        Node<U>* removed = prev->getLink();
        prev->setLink(removed->getLink());
        delete removed;
        this->cnt--;
    }
}

template<typename U>
int LinkedList<U>::find(int query) {
    int index=0;
    for(Node<U>* p = getHead(); p!=nullptr; p = p->getLink()){
        if(p->hasData(query))
            return index;
        index++;
    }
}

template<typename U>
void LinkedList<U>::replace(int pos, U data) {
    if(this->empty()||!(pos>=0 && pos<size()))
        cout<<"error\n";
    Node<U>* node = getNode(pos);
    node->setData(data);
}

template<typename U>
void LinkedList<U>::sorted_insert(int co, int de){
    Polynomial polynomial(co,de);
    if(cnt!=0){
        Node<U>* p = getHead();
        for(int i=0; i<this->cnt; i++){
            Polynomial deg = p->getData();
            if(deg.getDegree()<=polynomial.getDegree()){
                insert(i,polynomial);
                break;
            }
            p=p->getLink();
        }
        if(p==nullptr){
            insert(this->cnt,polynomial);
        }
    }else{
        insert(0,polynomial);
    }
}
template<typename U>
void LinkedList<U>::display() {
    int zero=0;
    cout<<"f(x) = ";
    Node<U>* p = getHead();
    for(int i=0; i<(this->cnt)-1;i++){
        cout << fixed;
        cout.precision(1);
        Polynomial deg = p->getData();
        if(deg.getCoeff()!=0){
            cout<<deg.getCoeff()<<" x^"<<deg.getDegree()<<" + ";
        }else{
            zero++;
        }
        p=p->getLink();
    }
    p=p->getLink();
    if(p==nullptr){
        Polynomial deg = get((this->cnt)-1);
        if(deg.getCoeff()!=0){
            cout<<deg.getCoeff()<<" x^"<<deg.getDegree()<<"\n";
        }else{
            zero++;
        }
    }
    if(zero==this->cnt){
        cout<<"0\n";
    }
}

int main(){

    LinkedList<Polynomial> listA,listB;
    int n,co,de;
    cin>>n;
    for(int i=0;i<n; i++){
        cin>>co>>de;
        listA.sorted_insert(co,de);
    }

    cin>>n;
    for(int i=0;i<n; i++){
        cin>>co>>de;
        listB.sorted_insert(co,de);
    }
    listA.display();
    listB.display();

    LinkedList<Polynomial> listResult = listA+listB;
    listResult.display();
    return 0;
}