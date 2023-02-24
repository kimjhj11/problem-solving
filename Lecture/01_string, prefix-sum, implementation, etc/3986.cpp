#include <bits/stdc++.h>
using namespace std;

int n, ans;
string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        cin >> str;
        stack<char> s;
        for(char i : str){
            if(s.size() && s.top() == i) s.pop();
            else s.push(i);
        }
        if(!s.size()) ans++;
    }
    cout << ans << '\n';

    return 0;
}

// 뿌요뿌요 느낌으로 만나면 터트리기
// 알고리즘 분류
// 자료 구조
// 스택