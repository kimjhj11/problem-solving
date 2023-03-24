#include <bits/stdc++.h>
using namespace std;

int n, m, h, ans;
int a[104][104][104];
bool visited[104][104][104];

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

struct A
{
    int a;
    int b;
    int c;
};

// 1 익은 토마토, 0 익지않은 토마토, -1 빈칸

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> m >> n >> h;

    vector<A> tomato;
    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j][k];
                if(a[i][j][k] == 1){
                    tomato.push_back({i, j, k});
                }
            }
        }
    }

    if(!tomato.size()){
        cout << -1 << '\n';
        return 0;
    }

    queue<pair<A, int>> q;
    for(A t : tomato){
        q.push({t , 0});
        visited[t.a][t.b][t.c] = 1;
    }

    while(q.size()){
        int x = q.front().first.a;
        int y = q.front().first.b;
        int z = q.front().first.c;
        int cnt = q.front().second;
        q.pop();

        ans = max(ans, cnt);

        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
            if(visited[nx][ny][nz]) continue;
            if(a[nx][ny][nz] == -1) continue;
            visited[nx][ny][nz] = 1;
            a[nx][ny][nz] = 1;
            q.push({{nx, ny, nz}, cnt + 1});
        }
    }

    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j][k] == 0){
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

// 7569_토마토
// BFS