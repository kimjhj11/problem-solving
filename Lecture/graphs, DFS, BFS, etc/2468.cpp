#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, a[104][104], visited[104][104];
int height, cnt, ans = 1;

void dfs(int r, int x, int y){
    visited[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx > n || ny > n) continue;
        if(a[nx][ny] > r && !visited[nx][ny]) dfs(r, nx, ny);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> height;
            a[i][j] = height;
        }
    }

    for(int r = 1; r <= 100; r++){
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] > r && !visited[i][j]){
                    dfs(r, i, j);
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}