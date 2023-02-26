#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }
    
    while(m--){
        cin >> a >> b;
        swap(v[a - 1], v[b - 1]);
    }

    for(int i : v) cout << i << " ";

    return 0;
}

// 10813_공바꾸기
// 구현
// 시뮬레이션