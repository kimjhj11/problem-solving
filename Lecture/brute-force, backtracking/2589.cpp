#include <bits/stdc++.h>
using namespace std;

int n, m, mx, visited[54][54];
char a[54][54];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int x, int y){
    memset(visited, 0, sizeof(visited));
    visited[x][y] = 1;

    queue<pair<int,int>> q;
    q.push({x, y});

    while(q.size()){
        tie(x, y) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(visited[nx][ny]) continue;
            if(a[nx][ny] == 'L'){
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
                mx = max(mx, visited[nx][ny]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L'){
                bfs(i, j);
            }
        }
    }
    cout << mx - 1 << '\n';

    return 0;
}

// 2589_보물섬
// brute-force
// bfs