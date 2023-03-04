#include <bits/stdc++.h>
using namespace std;

int n;
int d[] = {2, 3, 5, 7};

bool isPrime(int n){
    for(int i = 2; i <= n / 2; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int num, int digit){
    if(digit == n){
        if(isPrime(num)){
            cout << num << '\n';
        }
    }

    for(int i = 1; i <= 9; i += 2){
        if(isPrime(num * 10 + i)){
            dfs(num * 10 + i, digit + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    // 첫 소수는 2, 3, 5, 7 으로 고정
    for(int i : {2, 3, 5, 7}){
        dfs(i, 1);
    }

    return 0;
}

// 2023_신기한소수
// 백트래킹
// 소수판정