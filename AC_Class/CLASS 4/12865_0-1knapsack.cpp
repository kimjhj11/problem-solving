#include <bits/stdc++.h>
using namespace std;

int n, k, dp[104][100004];
int w[100004], v[1004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= n; i++){ // 물건 순서
        for(int j = 1; j <= k; j++){ // 최대 무게

            // 물건 넣기가 가능하다면 비교해보기
            if(j - w[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                continue;
            }

            // 아니라면 기존 값 끌고가기
            dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][k] << '\n';
    return 0;
}

// 12865_평범한배낭
// DP
// 배낭문제
// 0-1 knapsack 문제로 동적 계획법을 사용하여 풀기