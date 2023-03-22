#include <bits/stdc++.h>
using namespace std;

int n, a[1004], dp[1004], ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j <= i; j++){ // 저장되있는 앞쪽 dp는 연속 순열 보장
            if(a[j] < a[i]){
                if(dp[j] > cnt){
                    cnt = dp[j];
                }
            }
        }
        dp[i] = ++cnt;
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
    return 0;
}

// 11053_가장긴증가하는부분수열
// DP