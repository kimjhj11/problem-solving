#include <bits/stdc++.h>
using namespace std;

int n, m;
string str;
unordered_map<int, string> mp1;
unordered_map<string, int> mp2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> str;
        mp1.insert({i, str});
        mp2.insert({str, i});
    }

    for(int i = 0; i < m; i++){
        cin >> str;
        if(atoi(str.c_str()) != 0){
            cout << mp1[atoi(str.c_str())] << '\n';
        }else{
            cout << mp2[str] << '\n';
        }
    }

    return 0;
}

//atoi ASCII to int
//stoi string to int

// 알고리즘 분류
// 자료 구조
// 해시를 사용한 집합과 맵