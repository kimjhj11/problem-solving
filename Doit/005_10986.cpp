#include <bits/stdc++.h>
using namespace std;

int n, m;
long long num, ans, cnt[1004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    long long sum[n] = {};

    // 누적 합 저장
    for(int i = 1; i <= n; i++){
        cin >> num;
        sum[i] = sum[i-1] + num;
    }

    // 누적 합 mod
    for(int i = 1; i <= n; i++){
        sum[i] %= m;
        if(sum[i] == 0) ans++;
        cnt[sum[i]]++;
    }

    for(int i = 0; i < m; i++){
        ans += cnt[i] * (cnt[i] - 1) / 2; // p / 2!
    }

    cout << ans << '\n';
    return 0;
}

// 10986_나머지합구하기
// 누적합