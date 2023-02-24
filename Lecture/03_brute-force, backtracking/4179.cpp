#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
char cc[1004][1004];
int r, c, f[1004][1004], x, y, p[1004][1004], ans;
int px, py;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int,int>> q;
    fill(&f[0][0], &f[0][0] + 1004 * 1004, INF);

    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> cc[i][j];
            if(cc[i][j] == 'F'){
                f[i][j] = 1;
                q.push({i, j});
            }else if(cc[i][j] == 'J'){
                px = i; py = j;
            }
        }
    }

    // fire bfs
    while(q.size()){
        tie(x, y) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(f[nx][ny] != INF || cc[nx][ny] == '#') continue;
            f[nx][ny] = f[x][y] + 1;
            q.push({nx, ny});
        }
    }

    // player bfs
    p[px][py] = 1;
    q.push({px, py});
    while(q.size()){
        tie(x, y) = q.front();
        q.pop();
        if(x == r - 1 || y == c - 1 || x == 0 || y == 0){
            ans = p[x][y];
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(p[nx][ny] || cc[nx][ny] == '#') continue;
            if(f[nx][ny] <= p[x][y] + 1) continue;
            p[nx][ny] = p[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if(ans) cout << ans << '\n';
    else cout << "IMPOSSIBLE" << '\n';

    return 0;
}

// 4179_불이야!
// bfs