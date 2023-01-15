#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        q.push(i); // 7 6 5 4 3 2 1
    }

    cout << '<';
    while(!q.empty()){
        for(int i = 0; i < (k - 1); i++){
            q.push(q.front()); // 2 1 7 6 5 4 3 2 1
            q.pop(); // 2 1 7 6 5 4 3
        }
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
    }
    cout << '>';

    return 0;
}

// 알고리즘 분류
// 구현
// 자료구조
// 큐