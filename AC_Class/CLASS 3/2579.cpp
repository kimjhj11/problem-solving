#include <bits/stdc++.h>
using namespace std;

int n, dp[304];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    dp[2] = max(a[0], a[1]) + a[2];

    for(int i = 3; i < n; i++){
        dp[i] = max(dp[i - 3] + a[i - 1], dp[i - 2]) + a[i];
    }

    cout << dp[n - 1] << '\n';
}

// 2579_계단오르기
// 다이나믹 프로그래밍