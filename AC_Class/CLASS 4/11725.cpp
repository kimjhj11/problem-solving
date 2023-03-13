#include <bits/stdc++.h>
using namespace std;

int n, ans[100004];
bool visited[100004];
vector<int> v[100004];

void dfs(int node){
    visited[node] = 1;
    for(int i : v[node]){
        if(visited[i]) continue;
        ans[i] = node;
        dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for(int i = 2; i <= n; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}

// 11725_트리의 부모 찾기
// 트리
// DFS, BFS
// 문제의 트리의 루트가 1이므로 1부터 탐색을 시작하여 뻗어 나갈 때, 
// 꺼내진 수의 노드가 부모가 됨