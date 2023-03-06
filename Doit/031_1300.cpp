#include <bits/stdc++.h>
using namespace std;

long long n, k, sp, mp, ep, cnt, ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> k;

    // binary search
    sp = 1; ep = k; // 목표값 k의 인덱스는 k보다 클수 없음
    while(sp <= ep){
        mp = (sp + ep) / 2;
        cnt = 0;

        // mp보다 작은 수의 개수
        for(int i = 1; i <= n; i++){
            cnt += min(mp/i, n); // 작은 수 카운트
        }

        if(cnt < k){
            sp = mp + 1;
        }
        else{
            ans = mp;   // 중앙값 저장
            ep = mp - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}

// 1300_K번째수
// 이분탐색
// 데이터의 크기와 구조를 보고 이진탐색 알고리즘을 떠올리는 것이 중요