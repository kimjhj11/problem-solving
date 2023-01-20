#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;

// 방향
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m, x, y;
int a[max_n][max_n], visited[max_n][max_n];
queue<pair<int, int>> q;
string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<m; j++){
            a[i][j] = str[j] - '0';   // scanf("%1d", &a[i][j]);
        }
    }

    // 시작 지점 (0, 0) 도착 지점 (n - 1, m - 1)
    visited[0][0] = 1;
    q.push({0, 0});

    while(q.size()){
        tie(x, y) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == 0) continue;
            if(visited[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] + 1; // 가중치
            q.push({nx, ny});
        }
    }

    cout << visited[n-1][m-1] << '\n';
    return 0;
}

// 2178_미로탐색
// 알고리즘 분류
// 그래프 이론
// 그래프 탐색
// 너비 우선 탐색