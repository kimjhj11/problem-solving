#include <bits/stdc++.h>
using namespace std;

int n, a[100004], dp[100004], ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    dp[0] = a[0]; ans = a[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}

// 1912_연속합
// DP