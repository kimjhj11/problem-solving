#include <bits/stdc++.h>
using namespace std;

int A, B, C, a, b, sum;
int t[100];

int main(){
    cin >> A >> B >> C;

    for(int i = 0; i < 3; i++){
        cin >> a >> b;
        for(int j = a; j < b; j++) t[j]++;
    }

    for(int &i : t){
        if(i){
            if(i == 1) sum += A;
            else if(i == 2) sum += B * 2;
            else if(i == 3) sum += C * 3;
        }
    }

    cout << sum << "\n";
    return 0;
}