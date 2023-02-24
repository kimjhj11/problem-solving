#include <bits/stdc++.h>
using namespace std;

string str;

bool vowels(int n){
    return n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
        cin >> str;
        if(str == "end") break;

        int cnt = 0, vcnt = 0, ccnt = 0;
        for(int i = 0; i < str.length(); i++){
            if(vowels(str[i])){
                cnt++;
                vcnt++;
                ccnt = 0;
            }else{
                ccnt++;
                vcnt = 0;
            }
            if(vcnt == 3 || ccnt == 3){
                cnt = 0; break;
            }
            if(i && str[i] == str[i-1]){
                if(!(str[i] == 'e' || str[i] == 'o')){
                    cnt = 0; break;
                }
            }
        }

        if(!cnt) cout << "<" << str << "> is not acceptable. \n";
        else cout << "<" << str << "> is acceptable. \n";
    }

    return 0;
}

// 4659_비밀번호발음하기
// string