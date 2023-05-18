#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    
    answer += toupper(s[0]);
    for(int i = 1; i < s.length(); i++){
        if(s[i-1] == ' ')
            answer += toupper(s[i]);
        else
            answer += tolower(s[i]);
    }
    
    return answer;
}

// lev2_JadenCase_문자열_만들기
// toupper(), tolower()는 공백과 숫자 영향을 받지 않는다.
// 문제처럼 알파벳만 거르는 문제라면 최적