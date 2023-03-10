#include <bits/stdc++.h>
using namespace std;

int n;

void hanoi(int n, int sp, int mp, int ep){ // (개수, 시작, 중간, 끝)
    if(n == 1){ // 마지막 한개면 끝
        cout << sp << " " << ep << '\n';
    }else{
        // 하노이탑
        // 1. n-1개의 원판을 시작에서 끝을 거쳐 중간으로 이동
        // 2. 제일 큰판 이동
        // 3. n-1개의 원판을 중간에서 시작을 거쳐 끝으로 이동
        hanoi(n-1, sp, ep, mp);
        cout << sp << " " << ep << '\n';
        hanoi(n-1, mp, sp, ep);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;

    // 하노이탑 최소이동횟수는 개수 n 일때, n^2-1
    cout << (1 << n) - 1 << '\n';

    // n 개일때 1 -> 3 이동
    hanoi(n, 1, 2, 3);

    return 0;
}

// 11729_하노이탑 이동순서
// 재귀