#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> um;
int n, m, c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while(n--){
        cin >> c;
        um[c]++;
    }
    cin >> m;
    while(m--){
        cin >> c;
        cout << um[c] << '\n';
    }
    return 0;
}

// 10816_숫자 카드 2

// 알고리즘 분류
// 자료 구조
// 정렬
// 이분 탐색
// 해시를 사용한 집합과 맵