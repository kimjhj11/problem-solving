#include <bits/stdc++.h>
using namespace std;

int n, a[1000004], ans[1000004];
stack<int> s;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    memset(ans, -1, sizeof(ans));

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        // stack에 인덱스를 넣고 큰수 만나면 전체비움
        while(s.size() && a[s.top()] < a[i]){
            ans[s.top()] = a[i]; //-1 조건이 있기에 -1 배열에 따로 넣기
            s.pop();
        }
        s.push(i); // 다시 구간 시작
    }
    
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}

// 17298_오큰수
// stack