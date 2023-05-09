#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    stack<char> stk;

    for(char c : s){
        if(c == ')' && stk.size()) stk.pop();
        else stk.push(c);
    }

    return stk.empty();
}

// lev2_올바른괄호