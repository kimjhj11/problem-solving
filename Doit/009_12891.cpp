#include <bits/stdc++.h>
using namespace std;

int s, p, myArr[4], checkArr[4], checkAns, ans;
string str;

void add(char c){
    switch (c)
    {
    case 'A':
        myArr[0]++;
        if(myArr[0] == checkArr[0]){
            checkAns++;
        }
        break;
    case 'C':
        myArr[1]++;
        if(myArr[1] == checkArr[1]){
            checkAns++;
        }
        break;
    case 'G':
        myArr[2]++;
        if(myArr[2] == checkArr[2]){
            checkAns++;
        }
        break;
    case 'T':
        myArr[3]++;
        if(myArr[3] == checkArr[3]){
            checkAns++;
        }
        break;
    default:
        break;
    }
}

void remove(char c){
    switch (c)
    {
    case 'A':
        if(myArr[0] == checkArr[0]){
            checkAns--;
        }
        myArr[0]--;
        break;
    case 'C':
        if(myArr[1] == checkArr[1]){
            checkAns--;
        }
        myArr[1]--;
        break;
    case 'G':
        if(myArr[2] == checkArr[2]){
            checkAns--;
        }
        myArr[2]--;
        break;
    case 'T':
        if(myArr[3] == checkArr[3]){
            checkAns--;
        }
        myArr[3]--;
        break;
    default:
        break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> p;
    cin >> str;

    for(int i = 0; i < 4; i++){
        cin >> checkArr[i];
        if(checkArr[i] == 0) {
            checkAns++;
        }
    }

    // 시작 p 문자열 처리
    for(int i = 0; i < p; i++){
        add(str[i]);
    }
    if(checkAns == 4) {
        ans++;
    }

    // 슬라이딩 윈도우
    for(int i = p; i < s; i++){
        int j = i - p;

        add(str[i]);
        remove(str[j]);

        if(checkAns == 4) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}

// 12891_DNA비밀번호
// 문자열
// 슬라이딩윈도우