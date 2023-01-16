#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++) q.push(i);
    while(q.size() > 1){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << '\n';
    return 0;
}

// 2164 - 카드2
// 알고리즘 분류
// 자료 구조
// 큐