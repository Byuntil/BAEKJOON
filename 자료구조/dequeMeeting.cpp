#include <iostream>
#include <string>

using namespace std;

class Person{
private:
    string name;
public:
    Person( string name) : name(name){}

    string getName(){
        return name;
    }
};
template<typename T>
class Queue{
protected:
    static const int MAX_QUEUE_SIZE =  100;
    int front;
    int rear;
    T* data[MAX_QUEUE_SIZE];

public:
    Queue() { front = 0; rear=0;}
    ~Queue(){}
    bool empty(){return front == rear;}
    bool full(){return (rear+1)%MAX_QUEUE_SIZE == front;}

    void enqueue(T* e);
    T* dequeue();
    T* peek();
};

template<typename T>
void Queue<T>::enqueue(T* e) {
    if(full())
        cout<<"full\n";
    else{
        rear = (rear+1)%MAX_QUEUE_SIZE;
        data[rear] = e;
    }
}

template<typename T>
T* Queue<T>::dequeue() {
    if(empty()){

    }
    else{
        front=(front+1)%MAX_QUEUE_SIZE;
        return data[front];
    }
}

template<typename T>
T* Queue<T>::peek() {
    if(empty()){

    }
    else{
        return data[(front+1)%MAX_QUEUE_SIZE];
    }
}

template<typename U>
class Deque:public Queue<U> {
public:
    void addRear(U* e);
    void addFront(U* e);
    U* deleteFront();
};

template<typename U>
void Deque<U>::addRear(U* e) {
    Queue<U>::enqueue(e);
}

template<typename U>
void Deque<U>::addFront(U* e) {
    if(Queue<U>::full()){
        cout<<"full\n";
    }else{
        Queue<U>::data[Queue<U>::front] = e;
        Queue<U>::front = (Queue<U>::front - 1 + Queue<U>::MAX_QUEUE_SIZE) % Queue<U>::MAX_QUEUE_SIZE;
    }
}

template<typename U>
U* Deque<U>::deleteFront() {
    return Queue<U>::dequeue();
}

int main(){
    Deque<Person> male;
    Deque<Person> female;

    int a=0,b,c;
    int n,time;
    string name;
    char sex, frontOrRear;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin >> time >> name >> sex >> frontOrRear;
        if (sex == 'm' && frontOrRear == 'F')
            male.addFront(new Person(name));
        else if (sex == 'm' && frontOrRear == 'R')
            male.addRear(new Person(name));
        else if (sex == 'f' && frontOrRear == 'F')
            female.addFront(new Person(name));
        else if (sex == 'f' && frontOrRear == 'R')
            female.addRear(new Person(name));

        while(true){
            if(male.empty()||female.empty()){
                if(time == n) {
                    if (male.empty()) {
                        b = 0;
                        c = 0;
                        while (!female.empty()) {
                            female.deleteFront();
                            c++;
                        }
                        cout << a << " " << b << " " << c << "\n";
                        break;
                    } else if (female.empty()) {
                        b = 0;
                        c = 0;
                        while (!male.empty()) {
                            male.deleteFront();
                            b++;
                        }
                        cout << a << " " << b << " " << c << "\n";
                        break;
                    } else if ((male.empty()) && (female.empty())) {
                        cout << a << " 0 0\n";
                    }
                }
                break;
            }
            else if(!male.empty()&&!female.empty()){
                cout<<"Matched : "<<male.deleteFront()->getName()<<" "<<female.deleteFront()->getName()<<"\n";
                a++;

                if(time == n) {
                    if (male.empty()) {
                        b = 0;
                        c = 0;
                        while (!female.empty()) {
                            female.deleteFront();
                            c++;
                        }
                        cout << a << " " << b << " " << c << "\n";
                        break;
                    } else if (female.empty()) {
                        b = 0;
                        c = 0;
                        while (!male.empty()) {
                            male.deleteFront();
                            b++;
                        }
                        cout << a << " " << b << " " << c << "\n";
                        break;
                    } else if ((male.empty()) && (female.empty())) {
                        cout << a << " 0 0\n";
                    }
                }
                break;
            }else{
                break;
            }
        }
    }
    return 0;
}

