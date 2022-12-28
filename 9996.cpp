#include <bits/stdc++.h>
using namespace std;

int n, idx;
string s, s1, s2, str;

int main(){
    cin >> n >> s;

    idx = s.find('*');
    s1 = s.substr(0, idx);
    s2 = s.substr(idx + 1);
    regex rgx(s1 + "[a-z]*" + s2);

    while(n--){
        cin >> str;
        cout << (regex_match(str, rgx) ? "DA" : "NE") << '\n';
    }

    return 0;
}

// 문자열
// 정규표현식