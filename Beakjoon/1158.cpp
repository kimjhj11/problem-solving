#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    int cnt = 0;
    while(q.size()){
        int tmp = q.front();
        q.pop();

        cnt++;
        (cnt % k) ? q.push(tmp) : ans.push_back(tmp);
    }

    cout << "<";
    for(int i = 0; i < n - 1; i++){
        cout << ans[i] << ", ";
    }
    cout << ans[n - 1] << ">\n"; 

    return 0;
}

// 1158_요세푸스 문제
// 큐