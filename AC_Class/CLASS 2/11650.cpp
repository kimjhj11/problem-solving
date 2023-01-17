#include <bits/stdc++.h>
using namespace std;

int n, x, y;
vector<pair<int, int>> v;

bool cmp(pair<int, int> x, pair<int, int> y){
    if(x.first == y.first) return x.second < y.second;
    else return x.first < y.first;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n;

    while(n--){
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);

    for(auto i : v) cout << i.first << " " << i.second << '\n';
    return 0;
}