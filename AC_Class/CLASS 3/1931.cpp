#include <bits/stdc++.h>
using namespace std;

int n, a, b, ns_time, cnt;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());

    ns_time = v[0].first;
    cnt = 1;
    for(int i = 1; i < n; i++){
        if(v[i].second >= ns_time){
            ns_time = v[i].first;
            cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}

//1931_회의실배정
//greedy