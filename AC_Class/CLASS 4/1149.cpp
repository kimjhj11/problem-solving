#include <bits/stdc++.h>
using namespace std;

int n, R, G, B, dp[1004][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for(int i = 1; i <= n; i++){
        cin >> R >> G >> B;
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B;
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
    return 0;
}

// 1149_RGB 거리
// DP