#include <bits/stdc++.h>
using namespace std;

int t, n, cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n;
        for(int i = 5; i <= n; i *= 5){ // 10(2 * 5)의 개수 구하기
            cnt += n/i;
        }
        cout << cnt << '\n';
    }

    return 0;
}

//3474_교수가 된 현우
//수학
//정수론