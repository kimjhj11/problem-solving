#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int parent[55];
vector<int> truth, party[55];

int find_root(int x){
    // x가 root면, 그대로 반환
    if(x == parent[x]) return x;

    // x가 자식 노드면, 부모 노드에 대해 재귀 실행
    // return find_root(parent[x]);

    // ***이 때, parent[x]를 최종적으로 찾을 root 노드로 갱신한다.***
    return parent[x] = find_root(parent[x]);
}

void union_root(int x, int y) {
    // x, y 정점의 최상위 정점을 각각 찾는다. (속한 트리의 루트 노드를 찾는다.)
    x = find_root(x);
    y = find_root(y);
 
    if (x != y) {
        // 서로 다른 트리에 속한다면, 한 쪽의 트리를 다른 쪽에 붙인다.
        parent[x] = y;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 사람 수 n, 파티 수 m
    cin >> n >> m;

    // 진실을 아는 사람을 truth에 저장
    cin >> t;
    while(t--){
        int num;
        cin >> num;
        truth.push_back(num);
    }

    // 부모 노드를 본인으로 저장
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    // 같은 파티에 참석했다면 루트를 같게
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        
        int now, prev;
        for(int j = 0; j < num; j++){
            if(j == 0) cin >> now;
            else{
                prev = now;
                cin >> now;
                union_root(prev, now);
            }
            party[i].push_back(now);
        }
    }

    // 파티에 있는 사람과 진실을 아는 사람의 루트가 같다면 flag가 true,
    // 가능한 파티 수를 하나 줄인다
    for(vector<int> people : party){
        bool flag = false;
        for(int person : people){
            if(flag) break;
            for(int i : truth){
                if(find_root(person) == find_root(i)){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) m--;
    }

    cout << m << '\n';

    return 0;
}

// 1043_거짓말
// 분리집합 문제로 Union-Find 알고리즘 사용