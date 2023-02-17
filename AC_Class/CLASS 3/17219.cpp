#include <bits/stdc++.h>
using namespace std;

int n, m;
string str1, str2;
unordered_map<string, string> um;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    while(n--){
        cin >> str1 >> str2;
        um[str1] = str2;
    }

    while(m--){
        cin >> str1;
        cout << um[str1] << '\n';
    }
    
    return 0;
}

// 17219_비밀번호찾기
// hashmap
