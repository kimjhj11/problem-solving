#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, d;
vector<int> dist(10004, INF);
vector<pair<int,int>> v[10004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 도로 개수, 목표 길이
    cin >> n >> d;

    for(int i = 0; i < n; i++){
        // 시작, 끝, 길이
        int sp, ep, dis; 
        cin >> sp >> ep >> dis;
        if(ep > d || ep - sp < dis) continue;
        v[ep].push_back({sp, dis});
    }

    dist[0] = 0;
    for(int i = 1; i <= d; i++){
        dist[i] = dist[i - 1] + 1;
        
        for(pair<int,int> pp : v[i]){
            dist[i] = min(dist[i], dist[pp.first] + pp.second);
        }
    }
    
    // d까지의 최소 가중치 출력
    cout << dist[d] << '\n';
    return 0;
}

// 1446_지름길
// DP
// 다익스트라