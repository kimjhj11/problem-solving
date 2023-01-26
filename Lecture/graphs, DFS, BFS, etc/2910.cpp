#include <bits/stdc++.h>
using namespace std;

int n, c, num;
map<int, int> cnt, order;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return order[a.first] < order[b.first]; // 같으면 들어온 순서
    } 
    return a.second > b.second; // 다르면 횟수
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    for(int i=0; i<n; i++){
        cin >> num;
        cnt[num]++;
        if(order[num] == 0){
            order[num] = i + 1; // 처음 들어온 순서만 저장 
        } 
    }

    vector<pair<int,int>> v(cnt.begin(), cnt.end());
    sort(v.begin(), v.end(), cmp);

    for(auto i : v){
        for(int j = 0; j < i.second; j++){
            cout << i.first << " ";
        }
    }
    return 0;
}

// 2910_빈도정렬
// 정렬
// 해시맵