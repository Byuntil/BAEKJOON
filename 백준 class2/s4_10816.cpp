#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> a, b;
    int n=0,m=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int target;
    cin>>m;
    int *c = new int[m];
    for(int i=0; i<m; i++) {
        int x;
        cin >> x;
        b.push_back(x);
        c[i]=0;
        target = b.at(i);
        int right = n-1, left = 0;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (a.at(mid) == target) {
                for(int j=mid; j <= right; j++){
                    if(a.at(j) == target){
                        c[i]++;
                    }
                }
                for(int k=mid-1; k >= left; k--){
                    if(a.at(k)==target){
                        c[i]++;
                    }
                }
                break;
            } else if (a.at(mid) > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
            cout<<c[i]<<" ";
    }

    return 0;
}