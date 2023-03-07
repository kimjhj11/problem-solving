#include <bits/stdc++.h>
using namespace std;

int div_n = 1000000, pp = 1500000;
long long n, dp[1500004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i < pp; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % div_n;
    }

    cout << dp[n % pp] << '\n';
    return 0;
}

// 2749_피보나치수3
// 수학
// 실제 피보나치 수열 값이 아닌 특정 값으로 나눈 결과를 원하기 때문에
// 나머지 값만 저장하고 피사노주기를 활용하여, 오버플로우 방지