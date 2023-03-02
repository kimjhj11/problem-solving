#include <bits/stdc++.h>
using namespace std;

int n, m, ans[10];
vector<int> v;

void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i < n; i++){
        ans[cnt] = v[i];
        dfs(i, cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    dfs(0, 0);

    return 0;
}

// 15657_N과M(8)
// 백트래킹