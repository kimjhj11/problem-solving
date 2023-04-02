#include <bits/stdc++.h>
using namespace std;

int n, m, a[1004][1004];
bool visited[1004][1004][2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct A
{
    int a;
    int b;
    int c;
};

int bfs(){
    queue<pair<A, int>> q;
    q.push({{0, 0, 0}, 0});
    visited[0][0][0] = 1;

    while(q.size()){
        int x = q.front().first.a;
        int y = q.front().first.b;
        int cnt = q.front().first.c;
        int bw = q.front().second;
        q.pop();

        if((x == n-1) && (y == m-1)){
            return cnt + 1;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            // 일반적인 bfs 진행
            if(a[nx][ny] == 0 && visited[nx][ny][bw] == 0){
                visited[nx][ny][bw] = 1;
                q.push({{nx, ny, cnt + 1}, bw});
            }
            // 벽이면 부수고 가는 진행
            else if(a[nx][ny] == 1 && bw == 0){
                visited[nx][ny][bw + 1] = 1;
                q.push({{nx, ny, cnt + 1}, bw + 1});
            }
            
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;

    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < m; j++){
            a[i][j] = str[j] - '0';
        }
    }

    if(a[0][0]){
        cout << -1 << '\n';
        return 0;
    }

    cout << bfs() << '\n';
    return 0;
}

// 2206_벽 부수고 이동하기
// BFS
// 브루트포스 + BFS를 사용하면 시간초과
// visited[n][m][2] 3차원 배열을 사용하여 체크를 하며 bfs를 진행