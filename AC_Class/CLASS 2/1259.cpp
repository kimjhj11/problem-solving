#include <bits/stdc++.h>
using namespace std;

int reverse_Num(int n){
    int rvs_n = 0, rmdr;

    while(n != 0){
        rmdr = n%10;
        rvs_n = rvs_n * 10 + rmdr;
        n /= 10;
    }
    
    return rvs_n;
}

int main(){
    int n, rvs_n;

    while(1){
        cin >> n;
        if(n == 0) break;
        rvs_n = reverse_Num(n);
        if(n == rvs_n) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}