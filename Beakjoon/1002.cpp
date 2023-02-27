#include <bits/stdc++.h>
using namespace std;

int x, y, x_1, y_1, r, r1, t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> x >> y >> r >> x_1 >> y_1 >> r1;
        int d = pow((x - x_1), 2) + pow((y - y_1), 2); // 두 좌표의 거리 ^ 2
        int pd = pow((r + r1), 2); // 원 외부
        int md = pow((r - r1), 2); // 원 내부

        if(d == 0){
            if(md == 0){
                cout << -1 << '\n'; 
            }else{
                cout << 0 << '\n';
            }
        }
        else if(d == pd || d == md){
            cout << 1 << '\n';
        }
        else if(md < d && d < pd){
            cout << 2 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }
    return 0;
}

// 1002_터렛
// 수학
// 기하학
// 많은 조건 분기