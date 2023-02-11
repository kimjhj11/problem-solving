#include <bits/stdc++.h>
using namespace std;

int t, n, f[41];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i < 41; i++){
        f[i] = f[i-1] + f[i-2];
    }

    cin >> t;
    while(t--){
        cin >> n;
        if(n == 0) cout << "1 0" << '\n';
        else cout << f[n - 1] << " " << f[n] << '\n';
    }
    return 0;
}

// 1003_피보나치함수
// dp