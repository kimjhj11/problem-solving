#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = n - 1; i >= 0; i--){
        // 큰수부터 선택해서 나누고 카운트
        cnt += k / a[i];
        // 나머지만 저장
        k %= a[i];
    }

    cout << cnt << '\n';
    return 0;
}

// 11047_동전 0
// 그리디 알고리즘