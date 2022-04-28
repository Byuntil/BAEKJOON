#include <iostream>
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
    Queue(){front = rear = 0; count=0;}
    ~Queue(){}
    bool empty(){return front == rear;}
    bool full(){return (rear+1)%MAX_QUEUE_SIZE == front;}

    void enqueue(T e);
    T dequeue();
    T peek();
    int size();
    void display();
};

template<typename T>
void Queue<T>::enqueue(T e) {
    if(full())
        throw "error: queue is full";
    else{
        rear = (rear+1)%MAX_QUEUE_SIZE;
        data[rear] = e;
        count++;
    }
}

template<typename T>
T Queue<T>::dequeue() {
    if(empty())
        throw "error: queue is empty";
    else{
        front=(front+1)%MAX_QUEUE_SIZE;
        count--;
        return data[front];
    }
}

template<typename T>
T Queue<T>::peek() {
    if(empty())
        throw "error: queue is empty";
    else{
        return data[(front+1)%MAX_QUEUE_SIZE];
    }
    return nullptr;
}

template<typename T>
int Queue<T>::size() {
    return count;
}

template<typename T>
void Queue<T>::display() {
    cout<<"queue : \n";
    int maxi = (front<rear)?rear:rear+MAX_QUEUE_SIZE;
    for(int i = front+1; i<maxi; i++) {
        cout<<data[i%MAX_QUEUE_SIZE];
        cout<<"\n";
    }
}

int main(){
    Queue<int> queue;
    for(int i=1; i<10;i++){
        queue.enqueue(i);
    }
    queue.display();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.display();
    return 0;
}