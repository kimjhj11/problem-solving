#include <bits/stdc++.h>
using namespace std;

int r, c, cnt, visited[26], ans;
char a[20][20];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int cnt){
    ans = max(ans, cnt);

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if(visited[(int)a[nx][ny] - 'A']) continue;

        visited[(int)a[nx][ny] - 'A'] = 1;
        dfs(nx, ny, cnt + 1);
        visited[(int)a[nx][ny] - 'A'] = 0;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }

    visited[(int)a[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << ans << '\n';

    return 0;
}

// 1987_알파벳
// DFS
// 백트래킹