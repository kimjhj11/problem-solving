#include <bits/stdc++.h>
using namespace std;

int n;
string a[70];

void dac(int x, int y, int size){
    if(size == 1){
        cout << a[x][y];
        return;
    }
    char check = a[x][y];
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(a[i][j] != check){
                cout << '(';
                dac(x, y, size / 2);
                dac(x, y + size / 2, size / 2);
                dac(x + size / 2, y, size / 2);
                dac(x + size / 2, y + size / 2, size / 2);
                cout << ')';
                return;
            }
        }
    }
    cout << a[x][y];
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    dac(0, 0, n);

    return 0;
}

// 1992_쿼드트리
// 분할정복
// 재귀