#include <bits/stdc++.h>
using namespace std;

int n, m, s[100004], num;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> num;
        s[i] = s[i-1] + num;
    }

    for(int i = 0; i < m; i++){
        int n1, n2;
        cin >> n1 >> n2;
        cout << s[n2] - s[n1 - 1] << '\n';
    }

    return 0;
}

//11659_구간합구하기4
//누적합