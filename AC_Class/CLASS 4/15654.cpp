#include <bits/stdc++.h>
using namespace std;

int n, m, num, visited[10], ans[10];
vector<int> v;

void solve(int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        visited[i] = 1;

        ans[cnt] = v[i];
        solve(cnt + 1);

        visited[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    solve(0);

    return 0;
}

// 15654_N과M(5)
// backtracking