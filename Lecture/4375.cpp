#include <bits/stdc++.h>
using namespace std;

int n, ones, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> n){
        ones = 1; ans = 1;
        while(1){
            if(ones % n == 0){
                cout << ans << '\n';
                break;
            }else{
                ones = (ones * 10) + 1;
                ones = ones % n;
                ans++;
            }
        }
    }
    return 0;
}

//범위초과를 방지하기위해 모듈러로 미리 자르기
