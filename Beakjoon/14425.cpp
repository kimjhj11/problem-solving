#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
string str;
unordered_map<string, bool> um;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while(n--){
        cin >> str;
        um[str] = 1;
    }

    while(m--){
        cin >> str;
        if(um[str]){
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}

// 14425_문자열집합
// hashmap