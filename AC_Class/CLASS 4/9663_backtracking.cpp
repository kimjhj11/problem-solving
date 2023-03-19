#include <bits/stdc++.h>
using namespace std;

int n, c[20], ans;

void solve(int now){
    // 칸을 다 채웠다면 정답++
    if(now == n){
        ans++;
        return;
    }

    for(int row = 0; row < n; row++){
        // now는 행, row는 열
        c[now] = row;

        // 이전 행들의 열이 중복되는지 & 대각선에 위치하는지
        bool fail = false;
        for(int pre = 0; pre < now; pre++){
            if(c[pre] == c[now] || abs(c[now] - c[pre]) == now - pre){
                fail = true;
                break;
            }
        }
        if(fail) continue;

        // 다음 행으로
        solve(now + 1);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    solve(0);

    cout << ans << '\n';
    return 0;
}

// 9663_N-Queen
// 브루트포스
// 백트래킹
// 문제의 조건이 중복 퀸을 배치하므로 행,열,대각선이 일치하면 안된다
// 한행에 하나 이상 들어갈 수 없음으로 행열의 2차원 배열이 아니라 1차원만 써도 가능