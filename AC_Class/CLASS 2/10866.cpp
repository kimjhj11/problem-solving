#include <bits/stdc++.h>
using namespace std;

int n, m;
string str;

struct homemade_deck{
    int idx = 0;
    int a[100004];

    void push_front(int x){
        for(int i=idx; i > 0; i--){
            a[i] = a[i - 1];
        }
        a[0] = x;
        idx++;
    }

    void push_back(int x){
        a[idx] = x;
        idx++;
    }

    int pop_front(){
        if(empty()) return -1;
        int temp = a[0];
        for(int i=0; i<idx; i++){
            a[i] = a[i+1];
        }
        idx--;
        return temp;
    }

    int pop_back(){
        if(empty()) return -1;
        idx--;
        return a[idx];
    }

    int size(){
        return idx;
    }

    int empty(){
        return idx ? 0 : 1;
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

    homemade_deck d;

    cin >> n;
    while(n--){
        cin >> str;
        if(str == "push_front"){
            cin >> m;
            d.push_front(m);
        }

        if(str == "push_back"){
            cin >> m;
            d.push_back(m);
        }

        if(str == "pop_front"){
           cout << d.pop_front() << '\n';
        }

        if(str == "pop_back"){
           cout << d.pop_back() << '\n';
        }

        if(str == "size"){
            cout << d.size() << '\n';
        }

        if(str == "empty"){
            cout << d.empty() << '\n';
        }

        if(str == "front"){
            cout << d.front() << '\n';
        }

        if(str == "back"){
            cout << d.back() << '\n';
        }
    }

    return 0;
}

// 10866_덱
// 알고리즘 분류
// 자료 구조
// 덱