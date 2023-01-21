#include <bits/stdc++.h>
using namespace std;

int n, m, a, cnt;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    } 

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(v[i] + v[j] == m) cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}