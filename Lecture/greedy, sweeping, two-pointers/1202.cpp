#include <bits/stdc++.h>
using namespace std;

int n, k, idx;
long long ans;
priority_queue<int, vector<int>, less<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    vector<pair<int,int>> gem(n); // 보석: 무게, 가격
    vector<int> bag(k); // 가방 무게

    for(int i = 0; i < n; i++){
        cin >> gem[i].first >> gem[i].second;
    }
    for(int i = 0; i < k; i++){
        cin >> bag[i];
    }

    // 무게순 정렬
    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());

    for(int i = 0; i < k; i++){
        // 무게 맞으면 큐에 push, 보석 idx는 따로 관리 (초기화 x)
        while (idx < n && bag[i] >= gem[idx].first){
            pq.push(gem[idx].second);
            idx++;
        }
        if(pq.size()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';

    return 0;
}

// 1202_보석도둑
// 그리디
// 정렬
// 우선순위큐