#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
string str;
unordered_map<string, int> names;
vector<string> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        names[str]++;
    }

    for(int i = 0; i < m; i++){
        cin >> str;
        if(names[str]){
            v.push_back(str);
            cnt++;
        } 
    }

    cout << cnt << '\n';
    sort(v.begin(), v.end());
    for(auto i : v) cout << i << '\n';

    return 0;
}

// 1764_듣보잡
// string
// sort
// hashmap