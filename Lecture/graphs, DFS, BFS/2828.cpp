#include <bits/stdc++.h>
using namespace std;

int n, m, j, p1, p2, np, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    p1 = 1;
    cin >> n >> m >> j;
    while(j--){
        p2 = p1 + m - 1;
        cin >> np;
        if(np >= p1 && np <= p2) continue; // 바구니 안에 있으면 패스
        if(np < p1){
            ans += p1 - np;
            p1 = np;
        }else{ // 크면
            p1 += np - p2;
            ans += np - p2;
        }
    }
    cout << ans << '\n';
    return 0;
}