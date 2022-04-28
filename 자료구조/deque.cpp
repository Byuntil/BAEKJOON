#include <iostream>
#include <string>
using namespace std;


template<typename T>
class Queue{
protected:
    static const int MAX_QUEUE_SIZE =  100;
    int front;
    int rear;
    T data[MAX_QUEUE_SIZE];
    int count;

public:
    Queue(): front(0), rear(0), count(0){}

    bool empty(){return front == rear;}
    bool full(){return (rear+1)%MAX_QUEUE_SIZE == front;}

    void enqueue(const T& e);
    T dequeue();
    T peek();
    int size();
};

template<typename T>
void Queue<T>::enqueue(const T& e) {
    if(full())
        cout<<"full\n";
    else{
        rear = (rear+1)%MAX_QUEUE_SIZE;
        data[rear] = e;
        count++;
    }
}

template<typename T>
T Queue<T>::dequeue() {
    if(empty())
        return "0";
    else{
        front=(front+1)%MAX_QUEUE_SIZE;
        count--;
        return data[front];
    }
}

template<typename T>
T Queue<T>::peek() {
    if(empty())
        return "0";
    else{
        return data[(front+1)%MAX_QUEUE_SIZE];
    }
}

template<typename T>
int Queue<T>::size() {
    return count;
}

template<typename U>
class Deque:public Queue<U> {
    public:
        Deque():Queue<U>(){}
        void addRear(U e);
        U deleteRear();
        void addFront(const U& e);
        U deleteFront();
        U getFront();
        U getRear();
};

template<typename U>
void Deque<U>::addRear(U e) {
    Queue<U>::enqueue(e);
}

template<typename U>
U Deque<U>::deleteRear() {
    if(Queue<U>::empty()) {
        return "0";
    }else{
        Queue<U>::count--;
        U ret = Queue<U>::data[Queue<U>::rear];
        Queue<U>::rear = (Queue<U>::rear -1+ Queue<U>::MAX_QUEUE_SIZE)%Queue<U>::MAX_QUEUE_SIZE;
        return ret;
    }
}

template<typename U>
void Deque<U>::addFront(const U& e) {
    if(Queue<U>::full()){
        cout<<"full\n";
    }else{
        Queue<U>::count++;
        Queue<U>::data[Queue<U>::front] = e;
        Queue<U>::front = (Queue<U>::front - 1 + Queue<U>::MAX_QUEUE_SIZE) % Queue<U>::MAX_QUEUE_SIZE;
    }
}

template<typename U>
U Deque<U>::deleteFront() {
    return Queue<U>::dequeue();
}

template<typename U>
U Deque<U>::getFront() {
    return Queue<U>::peek();
}

template<typename U>
U Deque<U>::getRear() {
    if(Queue<U>::empty()) {
        return "0";
    }else{
        return Queue<U>::data[Queue<U>::rear];
    }
}


int main(){
    Deque<string> deque;
    int n;
    string s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        if(s=="add"){
            cin>>s;
            if(s=="front"){
                cin>>s;
                deque.addFront(s);
            }else if(s=="rear"){
                cin>>s;
                deque.addRear(s);
            }
        }else if(s=="delete"){
            cin>>s;
            if(s=="front"){
                string si = deque.deleteFront();
                if(si=="0"){
                    cout<<"empty\n";
                }else{
                    cout<<si<<"\n";
                }

            }else if(s=="rear"){
                string si=deque.deleteRear();
                if(si=="0"){
                    cout<<"empty\n";
                }else{
                    cout<<si<<"\n";
                }
            }
        }else if(s=="size"){
            cout<<deque.size()<<"\n";
        }else if(s=="empty"){
            bool empty = deque.empty();
            if(!empty){
                cout<<"not empty\n";
            }else{
                cout<<"empty\n";
            }
        }else if(s=="front"){
            string si = deque.getFront();
            if(si=="0"){
                cout<<"empty\n";
            }else{
                cout<<si<<"\n";
            }
        }else if(s=="rear"){
            string si = deque.getRear();
            if(si=="0"){
                cout<<"empty\n";
            }else{
                cout<<si<<"\n";
            }
        }
    }
    return 0;
}
