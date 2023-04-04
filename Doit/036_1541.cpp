#include <bits/stdc++.h>
using namespace std;

int ans;
string str;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> str;

    string num;
    bool isMinus = 0;
    for(int i = 0; i <= str.size(); i++){
        if(str[i] == '+' || str[i] == '-' || i == str.size()){
            if(isMinus){
                ans -= stoi(num);
            }else{
                ans += stoi(num);
            }
            num = "";

            if(str[i] == '-') isMinus = true;
            continue;
        }

        num += str[i];
    }

    cout << ans << '\n';
    return 0;
}

// 1541_잃어버린 괄호
// 그리디