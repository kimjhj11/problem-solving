#include <bits/stdc++.h>
using namespace std;

int n, num;
string str;

struct stk{
    int s[100004];
    int top = -1;

    void push(int x){
        s[++top] = x;
    }

    int pop(){
        if(empty()) return -1;
        
        return s[top--];
    }

    int size(){
        return top + 1;
    }

    bool empty(){
        // if(top < 0) return 1;
        // return 0;
        return top < 0;
    }

    int prt_top(){
        if(empty()) return -1;
        
        return s[top];
    }
};

int main(){
    cin >> n;
    stk s;

    while(n--){
        cin >> str;
        if(str == "push"){
            cin >> num;
            s.push(num);
        }
        if(str == "pop"){
            cout << s.pop() << '\n';
        }
        if(str == "size"){
            cout << s.size() << '\n';
        }
        if(str == "empty"){
            cout << s.empty() << '\n';
        }
        if(str == "top"){
            cout << s.prt_top() << '\n';
        }
    }

    return 0;
}

// 10828번 : 스택
// 스택 구현