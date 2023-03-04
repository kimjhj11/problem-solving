#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<pair<int,int>> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        if(v[i].second - i <= 0) continue;
        ans = max(ans, v[i].second - i);
    }

    cout << ans + 1 << '\n';
}

// 1377_버블소트
// 정렬