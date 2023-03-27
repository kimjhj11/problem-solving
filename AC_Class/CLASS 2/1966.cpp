#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> n >> m;

        priority_queue<int> pq;
        queue<pair<int,int>> q;

        for(int idx = 0; idx < n; idx++){
            int value;
            cin >> value;
            pq.push(value);
            q.push({idx, value});
        }

        int cnt = 1;
        while(q.size()){
            int idx = q.front().first;
            int value = q.front().second;
            q.pop();

            if(pq.top() == value){
                if(idx == m){
                    cout << cnt << '\n';
                    break;
                }
                else{
                    pq.pop();
                    cnt++;
                }
            }
            else{
                q.push({idx, value});
            }
        }
    }

    return 0;
}

// 1966_프린터큐