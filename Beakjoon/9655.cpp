#include <bits/stdc++.h>
using namespace std;

int n, dp[1004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i - 1], dp[i - 3]) + 1;
    }

    if(dp[n] % 2 == 1){
        cout << "SK\n";
    }else{
        cout << "CY\n";
    }

    return 0;
}

// 9655_돌게임
// DP