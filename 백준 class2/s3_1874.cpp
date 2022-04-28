/*
#include<iostream>
#include<stack>
#include<vector>
using namespace std;



int main(){
    stack<int> s1;
    vector<char> charStack;
    int n,num;
    int iter=1;
    s1.push(iter);
    charStack.push_back('+');
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>num;
        while(s1.top()!=num){
            if(s1.top()<num){
                ++iter;
                s1.push(iter);
                charStack.push_back('+');
            }else if(s1.top()>num){
                s1.pop();
                charStack.push_back('-');
            }
        }
        if(s1.top()==num){
            s1.pop();
            charStack.push_back('-');
        }
    }
    if(!s1.empty()){
        cout<<"NO";
    }else{
        for(char i : charStack){
            cout<<i<<"\n";
        }
    }
    return 0;
}*/
#include<iostream>
#include<vector>

using namespace std;

int n;
int cnt = 0;
int seq[100001];
vector<int> v;
vector<char> ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> seq[i]; // 수열 입력

    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
        ans.push_back('+');

        // 벡터가 비어있지않고,  cnt번째 수열이 벡터의 마지막 원소와 같을경우
        while (!v.empty() && v.back() == seq[cnt])
        {
            v.pop_back();
            ans.push_back('-');
            cnt++;
        }
    }

    if (!v.empty()) cout << "NO"; // 수열이 만들어졌다면 벡터가 비어있어야 하므로.
    else for (char an : ans) cout << an << '\n';

    return 0;
}
