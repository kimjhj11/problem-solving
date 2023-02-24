#include <bits/stdc++.h>
using namespace std;

int n, m, visited[10004], dp[10004], mn;
vector<int> v[10004];

int dfs(int num){
    visited[num] = 1;
    int ans = 1;
    for(auto i : v[num]){
        if(visited[i]) continue;
        ans += dfs(i);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        mn = max(dp[i], mn);
    }

    for(int i = 1; i <= n; i++){
        if(dp[i] >= mn) cout << i << " ";
    }

    return 0;
}

// 1325_효율적인해킹
// dfs, bfs