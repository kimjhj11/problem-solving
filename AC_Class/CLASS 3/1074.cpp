#include <bits/stdc++.h>
using namespace std;

int n, r, c, ans;

void Z(int x, int y, int size){
    if(x == r && y == c){
        cout << ans << '\n';
        return;
    }

    if(x <= r && r < x + size && y <= c && c < y + size){
        Z(x, y, size / 2);
        Z(x, y + size / 2, size / 2);
        Z(x + size / 2, y, size / 2);
        Z(x + size / 2, y + size / 2, size / 2);
    }
    else{
        ans += size * size;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r >> c;
    Z(0, 0, pow(2, n));

    return 0;
}

// 1074_Z
// 분할정복
// 재귀