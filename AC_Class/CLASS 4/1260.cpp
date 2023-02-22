#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<int> v[1004];
vector<int> ans;
bool visited[1004];

void dfs(int num){
    visited[num] = 1;
    ans.push_back(num);

    sort(v[num].begin(), v[num].end());
    for(int i : v[num]){
        if(visited[i]) continue;
        dfs(i);
    }
    return;
}

void bfs(int num){
    queue<int> q;
    q.push(num);
    visited[num] = 1;
    ans.push_back(num);

    while(q.size()){
        int x = q.front();
        q.pop();
        sort(v[x].begin(), v[x].end());

        for(int i : v[x]){
            if(visited[i]) continue;
            visited[i] = 1;
            q.push(i);
            ans.push_back(i);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;

    while(m--){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(s);
    for(int i : ans) cout << i << " ";
    cout << '\n';

    ans.clear();
    memset(visited, 0, sizeof(visited));

    bfs(s);
    for(int i : ans) cout << i << " ";
    cout << '\n';

    return 0;
}

// 1260_DFS와 BFS
// graph search
// DFS
// BFS