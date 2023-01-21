#include <bits/stdc++.h>
using namespace std;

const int max_n = 54;
int t, n, m, k, x, y, ans;
int a[max_n][max_n], visited[max_n][max_n];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y){
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx > n || ny > m) continue;
        if(a[nx][ny] && !visited[nx][ny]){
            dfs(nx, ny);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        fill(&a[0][0], &a[max_n - 1][max_n], 0);             // memset(a, 0, sizeof(a));
        fill(&visited[0][0], &visited[max_n - 1][max_n], 0); // memset(visited, 0, sizeof(visited));
        while(k--){
            cin >> x >> y;
            a[x][y] = 1;
        }
        ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] && !visited[i][j]){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

// 1012_유기농배추
// 알고리즘 분류
// 그래프 이론
// 그래프 탐색
// 너비 우선 탐색
// 깊이 우선 탐색