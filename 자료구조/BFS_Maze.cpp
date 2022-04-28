#include <iostream>
#include <vector>

using namespace std;

int n,m;
const int MAX = 50;
char map[MAX][MAX]={0,};
bool visited[MAX][MAX]={false,};

class Location2D{
public:
    int row;
    int column;
    int cost;
    Location2D(int r=0, int c=0, int cost=1):row(r), column(c), cost(cost) {}
};
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
};

template<typename T>
void Queue<T>::enqueue(T e) {
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
        throw "error: queue is empty";
    else{
        front=(front+1)%MAX_QUEUE_SIZE;
        count++;
        return data[front];
    }
}


bool is_valid(int r, int c){
    if(r<0||c<0||r>=MAX||c>=MAX)
        return false;
    if(visited[r][c]==true)
        return false;
    else
        return map[r][c]=='0'||map[r][c]=='T';
}
Location2D current;
int dfs(int s_r, int s_c){//(y,x)
    Queue<Location2D> queue;
    Location2D entry(s_r, s_c);
    vector<Location2D> directions = {Location2D(-1,0),Location2D(1,0), Location2D(0,-1), Location2D(0,1)};

    visited[s_r][s_c] = true;
    queue.enqueue(entry);

    while(!queue.empty()){
        current = queue.dequeue();
        if(map[current.row][current.column] == 'T')
            return current.cost;
        for(auto direction : directions){
            int next_row = current.row + direction.row;
            int next_column = current.column + direction.column;

            if(is_valid(next_row, next_column)){
                visited[next_row][next_column] = true;
                queue.enqueue(Location2D(next_row,next_column, current.cost+1));
            }
        }
    }
    return 0;
}
int main(){
    int s_r,s_c;
    cin>>n>>m;
    for(int i=0;i<n;i++){//row
        for(int j=0; j<m;j++){//column
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]=='S'){
                s_r=i;
                s_c=j;
                break;
            }
        }
    }
    cout<<dfs(s_r,s_c);
    return 0;
}