#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int n, m, r, ans;
int arr[104][104], t[104];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }

    fill(&arr[0][0], &arr[104 - 1][104], INF);
    for(int i = 0; i < r; i++){
        int a, b, l;
        cin >> a >> b >> l;
        arr[a][b] = l;
        arr[b][a] = l;
    }

    // 플로이드-와샬
    for(int k = 1; k <= n; k++){ // 거쳐가는 노드
		for(int i = 1; i <= n; i++){ // 출발 노드
			for(int j = 1; j <= n; j++){ // 도착 노드
				if(arr[i][k] + arr[k][j] < arr[i][j]){
				    arr[i][j] = arr[i][k] + arr[k][j];
                }
			}
        }
    }

    for(int i = 1; i <= n; i++){
        int cnt = t[i]; // 출발 노드
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(arr[i][j] <= m){ // 거쳐가는 노드
                cnt += t[j];
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}

// 14938_서강그라운드
// 플로이드-와샬
// 다익스트라로 푸는 것도 가능