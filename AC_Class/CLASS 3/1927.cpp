#include <bits/stdc++.h>
using namespace std;

int n, x;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> n;
    while(n--){
        cin >> x;
        if(x == 0){
            if(pq.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }

    return 0;
}

// 1927_최소힙
// 우선순위 큐