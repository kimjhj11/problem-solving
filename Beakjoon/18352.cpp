#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, k, x;
int dist[300004];
vector<int> v[300004];
bool check;

void bfs(int idx){
    dist[idx] = 0; // 시작위치 가중치는 0;

    queue<int> q;
    q.push(idx);
    while (q.size()){
        int now = q.front();
        q.pop();
        for(int next : v[now]){
            if(dist[next] > dist[now] + 1){
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 도시, 도로, 최단 거리, 출발 도시
    cin >> n >> m >> k >> x;

    // 연결 받기(단방향)
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    fill(dist, &dist[n + 1], INF);
    bfs(x);

    for(int i = 1; i <= n; i++){
        if(dist[i] == k){
            check = true;
            cout << i << '\n';
        }
    }
    if(!check) cout << -1 << '\n';

    return 0;
}

// 18352_특정거리의도시
// 다익스트라
// 다익스트라 알고리즘은 우선순위큐를 사용하지만, 이 문제의 가중치는 1이기 때문에 큐 이용