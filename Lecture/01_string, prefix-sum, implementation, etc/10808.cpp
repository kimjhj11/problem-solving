#include <bits/stdc++.h>
using namespace std;

int a[26];
string str;

int main(){
    cin >> str;
    for(char c : str) a[c - 'a']++;
    for(auto &c : a) cout << c << ' ';

    return 0;
}