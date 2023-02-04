#include <bits/stdc++.h>
using namespace std;

int n, x, bit;
string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        cin >> str;
        if(str == "add"){
            cin >> x;
            bit |= (1 << x);
        }
        else if(str == "remove"){
            cin >> x;
            bit &= ~(1 << x);
        }
        else if(str == "check"){
            cin >> x;
            if(bit & (1 << x)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(str == "toggle"){
            cin >> x;
            if(bit & (1 << x)) bit &= !(1 << x);
            else bit |= (1 << x);
        }
        else if(str == "all"){
            bit = ~(0 << 20);
        }
        else if(str == "empty"){
            bit = 0;
        }
    }
    
    return 0;
}

// 11723_집합
// bitmasking
// 메모리 제한 문제로 비트마스킹 사용
// 1 <= x <= 20이므로 int 32bit 중 20bit 사용