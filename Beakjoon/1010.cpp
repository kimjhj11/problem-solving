#include <bits/stdc++.h>
using namespace std;

int t, n, r, ans, temp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> t;
    
    while(t--){
        cin >> r >> n;
        ans = temp = 1;

        for(int i = n; i > n - r; i--){
            ans *= i;       // n * (n-1) * ... * (n-r+1)
            ans /= temp++;  // r * (r-1) * ... * 1
        }

        cout << ans << '\n';
    }

    return 0;
}

// 1010_다리놓기
// 조합 - 이항정리
// DP로도 해결 가능