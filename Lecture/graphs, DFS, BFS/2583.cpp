#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int visited[104][104];
int n, m, k;
vector<int> v;

int dfs(int x, int y){
    visited[x][y] = 1;
    int cnt = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue; // !!
        if(!visited[nx][ny]){
            cnt += dfs(nx, ny);
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    while(k--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1; i < y2; i++){       // !!
            for(int j = x1; j < x2; j++){
                visited[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                v.push_back(dfs(i, j));
            }
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for(auto i : v) cout << i << " ";
    return 0;
}

//2583_영역 구하기