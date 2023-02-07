#include <bits/stdc++.h>
using namespace std;

int n, l, r, a[54][54], visited[54][54], sum, cnt;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int,int>> q;
vector<pair<int,int>> v;

void bfs(int x, int y){
    visited[x][y] = 1;
    sum = a[x][y];

    while(q.size()){
        tie(x, y) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny]) continue;
            if(l <= abs(a[nx][ny] - a[x][y]) && abs(a[nx][ny] - a[x][y]) <= r){
                visited[nx][ny] = 1;
                q.push({nx, ny});
                v.push_back({nx, ny});
                sum += a[nx][ny];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    while(1){
        bool check = 0;
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    q = queue<pair<int,int>>();
                    v.clear();
                    q.push({i, j});
                    v.push_back({i, j});
                    bfs(i, j);
                }
                if(v.size() == 1) continue;
                for(pair<int,int> p : v){
                    a[p.first][p.second] = sum / v.size();
                    check = 1;
                }
            }
        }
        if(check) cnt++;
        else break;
    }
    cout << cnt << '\n';

    return 0;
}

// 16234_인구이동
// bfs