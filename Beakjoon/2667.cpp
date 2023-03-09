#include <bits/stdc++.h>
using namespace std;

int n, a[30][30], visited[30][30], cnt;
vector<int> ans;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
string str;

void dfs(int x, int y){
    visited[x][y] = 1;
    cnt++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(a[nx][ny] == 0 || visited[nx][ny]) continue;
        dfs(nx, ny);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < n; j++){
            a[i][j] = str[j] - '0';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 0 || visited[i][j]) continue;
            cnt = 0;
            dfs(i, j);
            ans.push_back(cnt);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(int i : ans) cout << i << '\n';

    return 0;
}

// 2667_단지번호붙이기
// DFS