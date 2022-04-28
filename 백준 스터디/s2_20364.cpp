#include<iostream>
#include<stack>
using namespace std;
/**
 * 경로를 다 조사
 * 경로중 true가 있으면 해당 true 반환
 * false이면 0반환
 */
bool check[1048577];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N,Q;
    cin>>N>>Q;
    for (int i = 0; i < Q; i++) {
        int a;
        cin>>a;
        int temp = a;
        stack<int> st;
        //오리 경로 체크
        while(temp!=0){
            st.push(temp);
            temp/=2;
        }
        bool result = true;
        //경로 확인
        while (!st.empty()) {
            temp = st.top();
            if(check[temp]){//못지나간다면
                cout<<temp<<"\n";
                result = false;
                break;
            }else{//지나간다면
                st.pop();
            }
        }
        if(result){
            cout<<"0"<<"\n";
            check[a]= true;
        }
    }

    return 0;
}