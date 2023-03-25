#include <bits/stdc++.h>
using namespace std;

int n, ans[2];
string a[104];
bool visited[104][104];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int i, int j){
    visited[i][j] = 1;

    queue<pair<int,int>> q;
    q.push({i , j});

    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny]) continue;
            if(a[x][y] == a[nx][ny]){
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // 일반 bfs
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]) continue;
            bfs(i, j);
            ans[0]++;
        }
    }

    // 적녹색약으로 교체
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 'R') a[i][j] = 'G';
        }
    }

    memset(visited, 0, sizeof(visited));

    // 적녹색약 BFS
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]) continue;
            bfs(i, j);
            ans[1]++;
        }
    }

    cout << ans[0] << " " << ans[1] << '\n';
    return 0;
}

// 10026_적록색약
// 그래프 탐색