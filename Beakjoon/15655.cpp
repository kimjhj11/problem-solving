#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v, ans;

void dfs(int idx){
    if(ans.size() == m){
        for(int i : ans){
            cout << i << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i < n; i++){
        if(ans.size() && v[i] == ans.back()) continue;
        ans.push_back(v[i]);
        dfs(i);
        ans.pop_back();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    dfs(0);

    return 0;
}

// 15655_N과M(6)
// 백트래킹
//
// if(v[i] == ans.back()) 는 vector ans가 사이즈가 없으면 인덱스 에러를 초래하는데
// if(ans.size() && v[i] == ans.back()) 이런식으로 앞 구문에 조건을 같이 걸어주면 괜찮다.
// 이유는 논리 AND 연산자(&&)가 두 피연산자를 계산할 때, 왼쪽에서 오른쪽으로의 결합성이 있으며,
// 첫 번째 피연산자가 0이 아닌 true 경우에만 두 번째 피연산자가 평가 되기 때문.
//
// MS 설명서에서는
//
// char *pch = 0;
// ...
// (pch) && (*pch = 'a');
//
// 이와 같은 방법으로 null 포인터 역참조를 방지할 수 있다고 나와있다.