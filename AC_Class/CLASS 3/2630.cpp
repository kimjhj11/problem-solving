#include <bits/stdc++.h>
using namespace std;

int n, v, w, b, a[131][131];
bool white, blue;

void dfs(int x, int y, int size){
    white = true;
    blue = true;
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(a[i][j] != 0) white = false;
            if(a[i][j] != 1) blue = false;
        }
    }
    if(white){
        w++; return;
    } 
    if(blue) {
        b++; return;
    }

    dfs(x, y, size / 2);
    dfs(x, y + size / 2, size / 2);
    dfs(x + size / 2, y, size / 2);
    dfs(x + size / 2, y + size / 2, size / 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    dfs(0, 0, n);

    cout << w << '\n';
    cout << b << '\n';
    return 0;
}

// 2630_색종이만들기
// 분할 정복
// 재귀
