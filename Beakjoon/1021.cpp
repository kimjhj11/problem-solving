#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
deque<int> dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }

    while(m--){
        int num;
        cin >> num;

        int pos;
        for(int i = 0; i < dq.size(); i++){
            if(dq[i] == num){
                pos = i;
                break;
            }
        }

        if(pos <= dq.size() / 2){
            while(dq.front() != num){
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
            dq.pop_front();
        }
        else{
            while(dq.front() != num){
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
            dq.pop_front();
        }
    }

    cout << ans << '\n';
    return 0;
}

// 1021_회전하는큐
// 자료구조
// 덱