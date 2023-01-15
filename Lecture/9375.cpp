#include <bits/stdc++.h>
using namespace std;

int n, m;
string content, catagory;

int main(){
    cin >> n;
    
    while(n--){
        map<string, int> mp;

        cin >> m;
        while(m--){
            cin >> content >> catagory;
            mp[catagory]++;
        }

        long long ans = 1;
        for(auto i : mp) ans *= (i.second + 1);

        cout << ans - 1 << '\n';
    }
    
    return 0;
}