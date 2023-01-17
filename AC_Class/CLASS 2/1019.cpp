#include <bits/stdc++.h>
using namespace std;

int n, m, _min = 2500, tmp;
string s[51];

int bw_check(int a, int b){
    char bw = 'B', ww = 'W';
    int b_cnt = 0, w_cnt = 0;
    int cnt = 1;

    for(int i = a; i < a + 8; i++){
        for(int j = b; j < b + 8; j++)
        {
            if(s[i][j] != bw) b_cnt++;
            if(s[i][j] != ww) w_cnt++;

            if(cnt%8 != 0) swap(bw, ww);
            cnt++;
        }
    }

    return min(b_cnt, w_cnt);
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    // 시작 지점 설정
    for(int i = 0; i <= n-8; i++){
        for(int j = 0; j <= m-8; j++){
            tmp = bw_check(i, j);
            if(tmp < _min) _min = tmp;
        }
    }
    cout << _min << '\n';
    return 0;
}

// 1019_체스판 다시 칠하기
// 알고리즘 분류
// 브루트포스 알고리즘