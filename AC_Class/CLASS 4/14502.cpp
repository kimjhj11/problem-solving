#include <bits/stdc++.h>
using namespace std;

int n, m, a[10][10], na[10][10], ans;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<pair<int,int>> virus;

void mapcopy(int ori[10][10], int copy[10][10]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            copy[i][j] = ori[i][j];
        }
    }
}

void bfs(){
    int nna[10][10];
    mapcopy(na, nna);

    queue<pair<int,int>> q;

    for(pair<int,int> v : virus){
        int x = v.first;
        int y = v.second;
        q.push({x, y});
    }

    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(nna[nx][ny] ==0){
                nna[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(nna[i][j] == 0) cnt++;
        }
    }

    ans = max(ans, cnt);
    return;
}

void make_wall(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(na[i][j] == 0){
                na[i][j] = 1;
                make_wall(cnt + 1);
                na[i][j] = 0;
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;

    // 지도 저장
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            // 바이러스 좌표 따로 저장
            if(a[i][j] == 2){
                virus.push_back({i, j});
            }
        }
    }

    // 벽 3개 세우기 경우 만들고, 경우 마다 bfs 돌리기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j]) continue;
            mapcopy(a, na);

            na[i][j] = 1;
            make_wall(1);
            na[i][j] = 0;
        }
    }

    cout << ans << '\n';
    return 0;
}

// 14502_연구소
// BFS
// 브루트포스
// 백트래킹
// ** 배열의 크기를 미리 선언하고 코드를 작성할때 copy 잘하기!!