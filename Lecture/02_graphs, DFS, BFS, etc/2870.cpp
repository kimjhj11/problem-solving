#include <bits/stdc++.h>
using namespace std;

int n;
string str, stk;
vector<string> v;

void go(){
    while(1){
        if(stk.length() && stk[0] == '0') stk.erase(stk.begin()); // stk.erase(0, 1);
        else break;
    }
    if(stk.length() == 0) stk = '0';
    v.push_back(stk);
    stk = "";
}

bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        cin >> str;
        stk = "";
        for(int i = 0; i < str.length(); i++){
            if(!(str[i] >= 'a' && str[i] <= 'z')) stk += str[i];
            else if(stk.length()) go();
        }
        if(stk.length()) go();
    }
    sort(v.begin(), v.end(), cmp);
    for(string i : v) cout << i << "\n";
    return 0;
}

// 2870_수학숙제
// 문자열
// 정렬
// 파싱
// 들어오는 글자가 최대 100 글자이므로 int가 아닌 string으로 처리