#include <bits/stdc++.h>
using namespace std;

int n, m, ch[2004];
vector<vector<int>> v;
bool isAns = false;

void dfs(int n, int cnt){
    if(cnt == 5){
        isAns = true;
        return;
    }

    ch[n] = true;
    for(int i : v[n]){
        if(ch[i]) continue;
        dfs(i, cnt + 1);
    }
    ch[n] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    v.resize(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        memset(ch, 0, sizeof(ch));
        dfs(i, 1);
        if(isAns) break;
    }

    if(isAns){
        cout << 1 << '\n';
    }else{
        cout << 0 << '\n';
    }

    return 0;
}

// 13023_ABCDE
// dfs
// 백트래킹