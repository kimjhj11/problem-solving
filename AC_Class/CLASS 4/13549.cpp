#include <bits/stdc++.h>
using namespace std;

int n, k, x, cnt, ans;
bool visited[100004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    queue<pair<int,int>> q;
    q.push({n, 0}); // 시작점, 카운트
    visited[n] = 1;

    while(q.size()){
        tie(x, cnt) = q.front();
        q.pop();

        if(x == k){
            ans = cnt;
            break;
        }

        // 가중치 0
        if(0 <= 2 * x && 2 * x <= 100000){
            if(!visited[2 * x]){
                q.push({2 * x, cnt});
                visited[2 * x] = 1;
            }
        }
        // 가중치 1
        if(0 <= x - 1 && x - 1 <= 100000){
            if(!visited[x - 1]){
                q.push({x - 1, cnt + 1});
                visited[x - 1] = 1;
            }
        }
        if(0 <= x + 1 && x + 1 <= 100000){
            if(!visited[x + 1]){
                q.push({x + 1, cnt + 1});
                visited[x + 1] = 1;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

// 13549_숨바꼭질3
// BFS
// 다익스트라
// 0-1 bfs
// 가중치가 다르기 때문에 우선 순위가 높은 방법을 큐의 앞에 배치한다