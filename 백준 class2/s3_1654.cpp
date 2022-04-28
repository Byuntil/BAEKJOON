#include<iostream>
using namespace std;
/**
 * 이분 탐색이용함
 */
int main(){
    int k, num;
    cin>>k>>num;
    long long low, mid,high;
    int max=0, answer=0;
    int line[100001];
    for (int i = 0; i < k; i++) {
        cin>>line[i];
        if(max<line[i]){
            max = line[i];
        }
    }
    low = 1;
    high = max;

    while(low<=high) {
        mid = (low + high)/2;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += line[i] / mid;
        }
        if(cnt>=num){
            low = mid + 1;
            if(answer<mid)
                answer = mid;
        }else{
            high = mid-1;
        }
    }

    cout<<answer;
    return 0;
}