#include <bits/stdc++.h>
using namespace std;

const int MOD = 1234567891;
int l;
long long sum, hashn = 1;
string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> str;

    for(int i = 0; i < l; i++){
        sum = (sum + (str[i] - 'a' + 1) * hashn) % MOD;
        hashn = (hashn * 31) % MOD;
    }
    cout << sum << '\n';

    return 0;
}

// 15829_해싱