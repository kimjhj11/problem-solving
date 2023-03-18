#include <bits/stdc++.h>
using namespace std;

int n, a[10004], dp[10004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    for(int i = 3; i <= n; i++){
        // i번째 와인을 먹는 선택지 (연속 3개는 X)
        // 1. 먹는다
        // -> 이전 와인도 먹었다면 -> ..OOXO O
        // -> 이전 와인을 먹지않았다면 -> ..OOX O
        // 2. 먹지않는다 -> ..OO X
        dp[i] = max({dp[i-3] + a[i-1] + a[i], dp[i-2] + a[i], dp[i-1]});
    }

    cout << dp[n] << '\n';
    return 0;
}

// 2156_포도주시식
// DP