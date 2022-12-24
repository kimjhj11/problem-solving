#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int n;
    int sum = 0;

    for(int i=0; i < 9; i++){
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    do{
        for(int i = 0; i < 7; i++) sum += v[i];
        if(sum == 100) break;
        sum = 0;
    }while(next_permutation(v.begin(), v.end()));

    v.pop_back(); v.pop_back();
    for(int i : v) cout << i << "\n";

    return 0;
}
