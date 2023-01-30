#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
        string str;
        cin.ignore();
        getline(cin, str);
        if(str == ".") break;
        
        stack<char> s;
        bool check = true;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '(' || str[i] == '[') s.push(str[i]);
            if(str[i] == ']'){
                if(s.size() && s.top() == '[') {
                    s.pop();
                }else{
                    check = false;
                    break;
                } 
            }
            if(str[i] == ')'){
                if(s.size() && s.top() == '(') {
                    s.pop();
                }else{
                    check = false;
                    break;
                } 
            }
        }

        if(check && !s.size()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}

// 4949_균형잡힌세상
// string
// stack