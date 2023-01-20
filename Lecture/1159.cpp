#include <bits/stdc++.h>
using namespace std;

int n, a[26];
string str, sum;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        a[str[0] - 'a']++;
    }

    for(int i=0; i < (sizeof(a)/sizeof(*a)); i++){
        if(a[i] >= 5) sum += i + 'a';
    }

    if(sum.size()) cout << sum << "\n";
    else cout << "PREDAJA" << "\n";

    return 0;
}