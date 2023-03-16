#include <bits/stdc++.h>
using namespace std;

int l, c, nov;
char vowels[] = {'a', 'e', 'i', 'o', 'u'};
vector<int> v, ans;

void dfs(int n){
    if(ans.size() == l){
        nov = 0;
        for(char c1 : ans){
            for(char c2 : vowels){
                if(c1 == c2){
                    nov++;
                    break;
                }
            }
        }

        if(nov >= 1 && l - nov >= 2){
            for(char c : ans) cout << c;
            cout << '\n';
            return;
        }
    }

    for(int i = n; i < c; i++){
        ans.push_back(v[i]);
        dfs(i + 1);
        ans.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> c;

    for(int i = 0; i < c; i++){
        char tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    dfs(0);
    return 0;
}

// 1759_암호만들기
// 백트래킹