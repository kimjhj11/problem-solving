#include <bits/stdc++.h>
using namespace std;

int n, num, zero, one, ans;
priority_queue<int> pos;
priority_queue<int, vector<int>, greater<int>> nag;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num > 1){
            pos.push(num);
        }
        else if(num == 1){
            one++;
        }
        else if(num == 0){
            zero++;
        }
        else{
            nag.push(num);
        }
    }

    // 양수 괄호
    while(pos.size() > 1){
        int n1 = pos.top();
        pos.pop();
        int n2 = pos.top();
        pos.pop();
        ans += n1 * n2;
    }

    // 양수 남은거 더해주기
    if(pos.size()){
        ans += pos.top();
        pos.pop();
    }

    // 음수 괄호
    while(nag.size() > 1){
        int n1 = nag.top();
        nag.pop();
        int n2 = nag.top();
        nag.pop();
        ans += n1 * n2;
    }

    // 음수 남은거 있고, 0있으면 음수 삭제, 아니면 남은거 더해주기
    if(nag.size()){
        if(zero){
            nag.pop();
            zero--;
        }
        else{
            ans += nag.top();
            nag.pop();
        }
    }

    // 1 남은거 더해주기
    ans += one;

    cout << ans << '\n';
    return 0;
}

// 1744_수묶기
// 그리디
// 정렬