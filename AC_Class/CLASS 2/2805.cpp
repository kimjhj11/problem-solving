#include <bits/stdc++.h>
using namespace std;

long long n, m, ans;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int sp = 0;
    int ep = v.back();

    while(sp <= ep){
        long long mp = (sp + ep) / 2;

        long long sum = 0;
        for(int i : v){
            if(i > mp) sum += i - mp;
        }

        if(sum < m){
            ep = mp - 1;
        }else{
            ans = max(ans, mp);
            sp = mp + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}

// 2805_나무 자르기
// 이분탐색
// 이분탐색 시작 지점을 v.front()로 했다가 틀려버린...