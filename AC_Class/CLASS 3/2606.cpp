#include <bits/stdc++.h>
using namespace std;

int n, com, a, b, visited[104];
vector<int> v[104];

int dfs(int n){
    visited[n] = 1;
    int ans = 1;
    for(int i : v[n]){
        if(visited[i]) continue;
        ans += dfs(i);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> com;
    for(int i = 0; i < com; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << dfs(1) - 1 << '\n';
    return 0;
}

// 2606_바이러스
// dfs, bfs
// 간선이 단방향인지 양방향인지 항상 체크할것