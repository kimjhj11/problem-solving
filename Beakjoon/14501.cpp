#include <bits/stdc++.h>
using namespace std;

int n, t, p, dp[16], ans;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> t >> p;
        v.push_back({t, p});
    }

    for(int i = 0; i <= n; i++){
        int time = v[i].first;
        int pay = v[i].second;

        dp[i] = max(ans, dp[i]);

        if(i + time <= n){
            dp[i + time] = max(dp[i + time], dp[i] + pay);
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
    return 0;
}

// 14501_퇴사
// DP