#include <bits/stdc++.h>
using namespace std;

int n;
string str;
vector<string> v;

// 1. 길이가 짧은 것부터, 2. 길이가 같으면 사전 순으로
bool cmp(string a, string b){
    if(a.length() == b.length()) return a < b;

    return a.length() < b.length();
}

int main(){
    cin >> n;
    while(n--){
        cin >> str;
        if(find(v.begin(), v.end(), str) == v.end())
            v.push_back(str);
    }
    sort(v.begin(), v.end(), cmp);

    for(auto i : v) cout << i << '\n';
    return 0;
}