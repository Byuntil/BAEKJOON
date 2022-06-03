#include<iostream>
#include<algorithm>

using namespace std;

//substr하면 시간 초과 남
int N, M;
int result;
string S;

bool check(const string &s);

void input() {
    cin >> N;
    cin >> M;
    cin >> S;
}

void solution() {
    for (int i = 0; i < M; i++) {
        if (S[i] == 'I') {
            string s = S.substr(i, 2 * N + 1);
            if (check(s) && s.size() == 2 * N + 1) {
                result++;
            }
        }
    }
}

bool check(const string &s) {
    bool is = true;
    int j;
    for (j = 0; j <= s.size(); j++) {
        if (is) {
            if (s[j] == 'I') {
                is = false;
            } else {
                break;
            }
        } else {
            if (s[j] == 'O') {
                is = true;
            } else {
                break;
            }
        }
    }
    if (j == s.size()) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    input();
    solution();
}

void printResult() {
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    printResult();
    return 0;
}
/*
 * #include <iostream>
#include <string>
using namespace std;
int n,m,ans=0;
string word;
//IOI 1
//IOIOI 2
//I한번나오면 n개수만큼 OI가 나올 때마다 답  1증가
int main(){
    cin >> n >> m >> word;
    for(int i = 1; i < word.size(); i++){
        int count = 0;
        if(word[i-1]=='I'){
            while(word[i]=='O' && word[i+1]=='I'){
                i+=2;
                count++;
                if(count == n ){ count--; ans++;}
            }
        }
    }
    cout << ans <<'\n';
}
 */