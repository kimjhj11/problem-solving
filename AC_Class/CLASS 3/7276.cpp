#include <bits/stdc++.h>
using namespace std;

int n, m, a[1004][1004], x, y, cnt;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int,int>> q;

void bfs(){
    while(q.size()){
        tie(x, y) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(a[nx][ny] == 0){
                a[nx][ny] = a[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                q.push({i, j});
            }
        }
    }

    bfs();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0){
                cout << -1 << '\n';
                return 0;
            }
            cnt = max(cnt, a[i][j]);
        }
    }
    cout << cnt - 1 << '\n';

    return 0;
}

// 7576_토마토
// bfs
// 탐색 횟수를 저장해야함과 동시에 탐색 시작 지점이 하나가 아니므로 
// 미리미리 큐에다가 순서를 확보 해두는 것이 중요