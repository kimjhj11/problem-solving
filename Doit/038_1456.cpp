#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 10000001;
ll A, B;
ll prime[MAX]; // 범위가 sprt 10^14
int ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> A >> B;

    for(int i = 2; i < MAX; i++){
        prime[i] = i;
    }

    // 에라토스테네스
    for(int i = 2; i <= sqrt(MAX); i++){
        if(prime[i] == 0) continue;

        for(int j = i + i; j < MAX; j += i){
            prime[j] = 0;
        }
    }

    for(int i = 2; i < MAX; i++){
        if(prime[i] == 0) continue;

        ll temp = prime[i];

        while((double)temp <= (double)B / (double)prime[i]){
            if((double)temp >= (double)A / (double)prime[i]) ans++;
            temp *= prime[i];
        }
    }

    cout << ans << '\n';
    return 0;
}

// 1456_거의소수
// 이항정리시 double 주의!!
// 범위 클 때 오버플로우 주의!!