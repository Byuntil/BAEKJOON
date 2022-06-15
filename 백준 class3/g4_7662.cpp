#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int T, k, n;
char c;
priority_queue<int, vector<int>, greater<>> minQ;
priority_queue<int, vector<int>, less<>> maxQ;
map<int, int> m; //반대쪽 큐에서 제거된 값인지 구별하기 위해 map에 해당 숫자가 현재 몇 개 남았는지 기록(배열은 너무 커서 map으로)

void input() {
    cin >> T;
}

void solution() {
    for (int i = 0; i < T; i++) {
        while (!minQ.empty()) {
            minQ.pop();
        }
        while (!maxQ.empty()) {
            maxQ.pop();
        }
        m.clear();

        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> c >> n;
            if (c == 'I') {
                minQ.push(n);
                maxQ.push(n);
                if (m.count(n) == 0) {
                    m[n] = 1;
                } else {
                    m[n]++;
                }
            } else {
                if (n == 1) { //최댓값 삭제
                    while (!maxQ.empty() && m[maxQ.top()] == 0) { //최댓값의 m값이 0이라면 이미 최소큐에서 삭제된 수여서 무효한 수 -> 스킵
                        maxQ.pop();
                    }
                    if (!maxQ.empty()) {
                        m[maxQ.top()]--;
                        maxQ.pop();
                    }
                } else if (n == -1) { //최솟값 삭제
                    while (!minQ.empty() && m[minQ.top()] == 0) { //최솟값의 m값이 0이라면 이미 최대큐에서 삭제된 수여서 무효한 수 -> 스킵
                        minQ.pop();
                    }
                    if (!minQ.empty()) {
                        m[minQ.top()]--;
                        minQ.pop();
                    }
                }
            }
        }
        while (!maxQ.empty() && m[maxQ.top()] == 0) {
            maxQ.pop();
        }
        while (!minQ.empty() && m[minQ.top()] == 0) {
            minQ.pop();
        }

        if (maxQ.empty() || minQ.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << maxQ.top() << " " << minQ.top() << "\n";
        }
    }
}

void solve() {
    input();
    solution();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
/*
 * #include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int n;
    while (t--)
    {
        cin >> n;
        char order;
        int num;
        multiset<int> ms;
        while (n--)
        {
            cin >> order >> num;
            if (order == 'I')
            {
                ms.insert(num);
            }
            else
            {
                if (!ms.empty() && num == -1)
                {
                    ms.erase(ms.begin());
                }
                else if (!ms.empty() && num == 1)
                {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
            }
        }
        if (ms.empty())
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            auto end_iter = ms.end();
            end_iter--;
            cout << *end_iter << ' ' << *ms.begin() << '\n';
        }
    }
    return 0;
}
 */