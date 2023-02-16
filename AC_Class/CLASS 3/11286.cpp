#include <bits/stdc++.h>
using namespace std;

int n, x;

// 우선순위큐 비교함수
struct cmp
{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    priority_queue<int, vector<int>, cmp> pq;

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

// 11286_절댓값 힙
// 자료구조
// 우선순위 큐