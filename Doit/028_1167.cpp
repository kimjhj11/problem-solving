#include <bits/stdc++.h>
using namespace std;

int n, c[100004], ans;
bool visited[100004];
vector<pair<int,int>> v[100004];

void dfs(int node, int cost){
    c[node] = max(c[node], cost);
    visited[node] = 1;
    for(pair<int,int> i : v[node]){
        if(visited[i.first]) continue;
        dfs(i.first, cost + i.second);
    }
    visited[node] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        while(1){
            int a, b;
            cin >> a;
            if(a == -1) break;
            cin >> b;
            v[num].push_back({a, b});
        }
    }

    dfs(1,0);

    int M = 1;
    for(int i = 1; i <= n; i++){
        if(c[M] < c[i]) M = i;
    }

    dfs(M, 0);

    for(int i = 1; i <= n; i++){
        ans = max(ans, c[i]);
    }

    cout << ans << '\n';

    return 0;
}

// 1167_트리의지름
// 트리
// dfs