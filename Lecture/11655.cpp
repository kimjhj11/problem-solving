#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    getline(cin, s);

    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            if((s[i] + 13) > 'z') s[i] = s[i] - ('z' - 'a' + 1) + 13;
            else s[i] += 13;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            if((s[i] + 13) > 'Z') s[i] = s[i] - ('Z' - 'A' + 1) + 13;
            else s[i] += 13;
        }
    }

    cout << s << "\n";
    return 0;
}