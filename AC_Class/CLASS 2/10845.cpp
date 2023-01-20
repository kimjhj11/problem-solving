#include <bits/stdc++.h>
using namespace std;

int n, m;
string str;

struct homemade_queue{
    int idx = 0;
    int a[100004];

    void push(int n){
        a[idx] = n;
        idx++;
    }

    int pop(){
        if(empty()) return -1;

        int temp = a[0];
        for(int i=0; i<idx; i++){
            a[i] = a[i+1];
        }
        idx--;
        return temp;
    }

    int size(){
        return idx;
    }

    int empty(){
        return idx ? 0 : 1; // empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
    }

    int front(){
        if(empty()) return -1;

        return a[0];
    }

    int back(){
        if(empty()) return -1;

        return a[idx-1];
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    homemade_queue q;

    cin >> n;
    while(n--){
        cin >> str;

        if(str == "push"){
            cin >> m;
            q.push(m);
        }

        if(str == "pop"){
           cout << q.pop() << '\n';
        }

        if(str == "size"){
            cout << q.size() << '\n';
        }

        if(str == "empty"){
            cout << q.empty() << '\n';
        }

        if(str == "front"){
            cout << q.front() << '\n';
        }

        if(str == "back"){
            cout << q.back() << '\n';
        }
    }

    return 0;
}