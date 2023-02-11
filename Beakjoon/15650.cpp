#include <bits/stdc++.h>
using namespace std;

int n, m, a[10];

void combi(int depth, int next){
    if(depth == m){
        for(int i = 0; i < m; i++){
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = next; i < n; i++){
        a[depth] = i + 1;
        combi(depth + 1, i + 1);
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    combi(0, 0);

    return 0;
}

// back-tracking