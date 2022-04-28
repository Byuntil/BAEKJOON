#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
//중위수식
using namespace std;
template<typename T>
class Stack{
private:
    int topN;
    T data[100];
public:
    Stack();
    ~Stack();
    void push(T element);
    T pop();
    T top();
    bool empty();
};

template<typename T>
Stack<T>::Stack() {
    topN = -1;
}

template<typename T>
Stack<T>::~Stack() {
}

template<typename T>
void Stack<T>::push(T element) {
    data[++topN] = element;
}

template<typename T>
T Stack<T>::pop() {
    return data[topN--];
}

template<typename T>
T Stack<T>::top() {
    return data[topN];
}

template<typename T>
bool Stack<T>::empty() {
    return topN ==-1;
}

double postfix(const vector<string>& expr) {
    double result = 0.0;
    Stack<double> stack;
    for (const auto &i: expr) {
        if (i=="+"||i=="-"||i=="*"||i=="/") {
            double second = stack.pop();
            double first = stack.pop();
            if (i == "+") {
                result = first + second;
                stack.push(result);
            } else if (i == "-") {
                result = first - second;
                stack.push(result);
            } else if (i == "*") {
                result = first * second;
                stack.push(result);
            } else {
                try {
                    if (second == 0) {
                        throw second;
                    }
                    result = first / second;
                    stack.push(result);
                } catch (double exception) {
                    cout << "zero division error";
                    exit(0);
                }
            }
        } else {
            stack.push(stod(i));
        }
    }
    return stack.pop();
}


//연산자 우선순위 결정
int priority(const string& c){
    int p = -1;
    if(c=="("||c==")"){
        p = 0;
    }else if(c=="+"||c=="-"){
        p = 1;
    }else{
        p = 2;
    }
    return p;
}
//중위 => 후위
vector<string> infix(const vector<string>& expr){
    vector<string> postfix;
    Stack<string> stack;

    for(const auto & i : expr){
        if(i=="+"||i=="-"||i=="*"||i=="/"){
            while(!stack.empty()){
                if(priority(stack.top())>=priority(i)){
                    postfix.push_back(stack.pop());
                }else
                    break;
            }
            stack.push(i);
        }else if(i=="("){
            stack.push(i);
        }else if(i==")"){
            while(!stack.empty()){
                string str = stack.pop();
                if(str=="(")
                    break;
                else
                    postfix.push_back(str);
            }
        }else{
            postfix.push_back(i);
        }
    }
    while(!stack.empty()){
        postfix.push_back(stack.pop());
    }
    return postfix;
}

int main() {
    vector<string> expr;
    string line, token;

    getline(cin, line);
    stringstream ss(line);

    while(getline(ss, token, ' '))
        expr.push_back(token);

    expr = infix(expr);

    try {
        cout << fixed << setprecision(2);
        cout << postfix(expr) << endl;
    }catch(runtime_error error){
        cout << error.what() << endl;
    }

    return 0;
}