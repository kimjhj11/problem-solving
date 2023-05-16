#include <bits/stdc++.h>
using namespace std;

int n;

void sol(int i, int j, int size){
    // 3x3 구조에서 (1,1)을 공백 처리
    // if(i % 3 == 1 && j % 3 == 1)

    // 큰 사이즈 가운데 공백
    if((i / size) % 3 == 1 && (j / size) % 3 == 1) {
        cout << " ";
    }
    else if (size / 3 == 0){
        cout << '*';
    }
    else{
        sol(i, j, size / 3);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sol(i, j, n);
        }
        cout << '\n';
    }
}

// 2447_별찍기-10
// 분할정복
// 재귀