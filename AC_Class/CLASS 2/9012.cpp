#include <bits/stdc++.h>
using namespace std;

int t;
string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> str;
        stack<char> s;
        for(char i : str){
            if(s.size() && s.top() == '(' && i == ')') s.pop();
            else s.push(i);
        }
        if(s.size()) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }

    return 0;
}

// 9012_괄호
// 알고리즘 분류
// 자료 구조
// 문자열
// 스택