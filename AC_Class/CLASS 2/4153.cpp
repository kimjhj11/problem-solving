#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main(){
    while(1){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c== 0) break;

        if(a > b) swap(a, b);
        if(b > c) swap(b, c);

        if(pow(a,2) + pow(b,2) == pow(c,2)) cout << "right" <<'\n';
        else cout << "wrong" << '\n';
    }

    return 0;
}