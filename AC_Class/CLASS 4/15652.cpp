#include <bits/stdc++.h>
using namespace std;

int n, m, a[10];

void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i <= n; i++){
        a[cnt] = i;
        dfs(i, cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    dfs(1, 0);

    return 0;
}

// 15652_N과M(4)
// 백트래킹