#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v, ans;

void dfs(int idx){
    if(ans.size() == m){
        for(int i : ans) cout << i << " ";
        cout << '\n';
        return;
    }

    int last = 0;
    for(int i = idx; i < n; i++){
        // 수열 마지막 값과 새로운 값이 같으면 패스 (중복 거름)
        if(last == v[i]) continue;
        last = v[i];

        // 수열 만들기 (중복 가능, 그러나 위의 조건에서 중복 거름)
        ans.push_back(v[i]);
        dfs(i);
        ans.pop_back();
    }
    return;
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
    dfs(0);

    return 0;
}