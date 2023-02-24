#include <bits/stdc++.h>
using namespace std;

int h, w, a[104][104];
char ch;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    memset(a, -1, sizeof(a));

    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            cin >> ch;
            if (ch == 'c'){
                a[i][j] = 0;
            }
            else if(a[i][j - 1] >= 0){
                a[i][j] = a[i][j - 1] + 1;
            } 
        }
    }

    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}

// 10709_기상캐스터
// 구현
// 시뮬레이션