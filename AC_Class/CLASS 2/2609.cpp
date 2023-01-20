#include <bits/stdc++.h>
using namespace std;

int a, b;

// 유클리드 호제법
int gcd(int a, int b){
    int c = a%b;
    while(c != 0){
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}

// (a * b) = (gcd * lcm)
int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int main(){
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
    cout << lcm(a, b) << '\n';
    return 0;
}