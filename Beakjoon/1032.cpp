#include <bits/stdc++.h>
using namespace std;

int n;
string s[50], ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    int len = s[0].size();

    // 세로 비교
    for(int i = 0; i < len; i++){
        char tmp = s[0][i];
        bool check = false;
        for(int j = 1; j < n; j++){
            if(tmp != s[j][i]){
                check = true;
                break;
            }
        }
        check ? ans += '?' : ans += tmp;
    }

    cout << ans << '\n';

    return 0;
}