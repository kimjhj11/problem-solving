#include <bits/stdc++.h>
using namespace std;

int p, n, m;
long long dp[10000004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> p;
    while(p--){
        cin >> n >> m;

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        int i = 3;
        while(1){
            dp[i] = (dp[i - 1] + dp[i - 2]) % m;
            if(dp[i] == 1 && dp[i - 1] == 0) break;
            i++;
        }

        cout << n << " " << i - 1 << '\n';
    }
    
    return 0;
}

// 9471_피사노주기
// DP
// 정수론
// 피보나치수열의 피사노주기를 구하는 문제
