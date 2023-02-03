#include <bits/stdc++.h>
using namespace std;

int n, m, num, mnum, ret, ans = 987654321;
vector<pair<int,int>> house, kfc;
vector<vector<int>> kfcCombi;
vector<int> v;

void combi(int start, vector<int> v){
    if(v.size() == m){
        kfcCombi.push_back(v);
        return;
    }
    for(int i = start + 1; i < kfc.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    // 입력
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            if(num == 2) kfc.push_back({i, j});
            else if(num == 1) house.push_back({i ,j});
        }
    }

    // 조합
    combi(-1, v);

    // 계산 및 출력
    for(vector<int> kfcs : kfcCombi){
        ret = 0;
        for(pair<int,int> i : house){
            mnum = 987654321;
            for(int j : kfcs){
                int temp = abs(i.first - kfc[j].first) + abs(i.second - kfc[j].second);
                mnum = min(mnum, temp);
            }
            ret += mnum;
        }
        ans = min(ans, ret);
    }
    cout << ans << '\n';

    return 0;
}

// 15686_치킨배달
// bruteforce
// back-tracking