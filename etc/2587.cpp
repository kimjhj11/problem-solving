#include <bits/stdc++.h>
using namespace std;

int n, sum, a[5];

int main(){
    for(int i=0; i<5; i++){
        cin >> n;
        a[i] = n;
        sum += n;
    }
    sort(a, a+5);
    cout << sum / 5 << '\n';
    cout << a[2] << '\n';
    return 0;
}

// 10_정렬_2_2587_대표값2