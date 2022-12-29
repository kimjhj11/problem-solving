#include <bits/stdc++.h>
using namespace std;

int n, k;

// 조합의수 = 이항계수
int combi(int n, int r){
    if(n == r || r == 0) return 1;
    else return combi(n-1, r-1) + combi(n-1, r);
}

int main(){
    cin >> n >> k;
    cout << combi(n, k) << '\n';
    return 0;
}