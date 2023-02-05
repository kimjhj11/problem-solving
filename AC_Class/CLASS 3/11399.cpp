#include <bits/stdc++.h>
using namespace std;

int n, sum, ans;
vector<int> p;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(cin >> n){
        p.push_back(n);
    }

    sort(p.begin(), p.end());

    for(int i : p){
        sum += i;
        ans += sum;
    }
    cout << ans << '\n';

    return 0;
}

// 11399_ATM
// greedy
// sort