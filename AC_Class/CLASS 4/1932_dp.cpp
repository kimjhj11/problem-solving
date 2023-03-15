#include <bits/stdc++.h>
using namespace std;

int n, a[504][504], dp[504][504], ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> a[i][j];
        }
    }
    
    dp[1][1] = a[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[n][i]);
    }

    cout << ans << '\n';
    return 0;
}

// 1932_정수삼각형
// DP
// 삼각형의 데이터이므로 2차원 배열의 반만 사용하여 인덱스 활용