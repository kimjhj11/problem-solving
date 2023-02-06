#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, cnt, visited[1004];
vector<int> vec[1004];

void dfs(int n){
    visited[n] = 1;
    for(int i : vec[n]){
        if(visited[i]) continue;
        dfs(i);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while(m--){
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        dfs(i);
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}

// 11724_연결요소의개수
// dfs, bfs