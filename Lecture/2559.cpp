#include <bits/stdc++.h>
using namespace std;

int n, k, t, ans = -1004;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    vector<int> v(n+1);

    for(int i = 1; i <= n; i++){
        cin >> t;
        v[i] = v[i-1] + t;
    }

    for(int i = k; i <= n; i++){
        ans = max(ans, v[i] - v[i-k]);
    }
    cout << ans << '\n';

    return 0;
}