#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<int> v(n+1);

    for(int k = 1; k <= n; k++){
        int tmp;
        cin >> tmp;
        v[k] = v[k-1] + tmp;
    }

    for(int k = 0; k < m; k++){
        int i, j;
        cin >> i >> j;
        cout << v[j] - v[i-1] << '\n';
    }

    return 0;
}