#include <bits/stdc++.h>
using namespace std;

int n, num;
vector<int> dp(14);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 12; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cin >> n;
    while(n--){
        cin >> num;
        cout << dp[num] << '\n';
    }
    
    return 0;
}

// 9095_1,2,3더하기
// dp