#include <bits/stdc++.h>
using namespace std;

int n, k, x, y, cnt, ans;
bool visited[500004][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    if(n == k){
        cout << 0 << '\n';
        return 0;
    }

    queue<pair<int,int>> q;
    q.push({n, 0});
    visited[n][0] = 1;
    while(q.size()){
        tie(x, cnt) = q.front(); q.pop();
        y = k + cnt * (cnt + 1) / 2; // cnt 수만큼 1 + 2 + 3 + ... + cnt (삼각형 공식)

        if(y > 500000){
            cout << -1 << '\n';
            break;
        }

        // 1. 현재 위치가 같거나 2. 대기할 수 있는 위치(홀/짝)에 있을 경우
        if(x == y || visited[y][cnt % 2]){
            cout << cnt << '\n';
            break;
        }

        for(int nx : {x - 1, x + 1, x * 2}){
            if(nx < 0 || nx > 500000) continue;
            if(visited[nx][(cnt + 1) % 2]) continue;
            visited[nx][(cnt + 1) % 2] = 1;
            q.push({nx, cnt + 1});
        }
    }

    return 0;
}

// 17071_숨바꼭질5
// BFS