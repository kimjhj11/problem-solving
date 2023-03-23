#include <bits/stdc++.h>
using namespace std;

int n, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        pq.push(num);
    }

    while(pq.size() != 1){
        int data1 = pq.top();
        pq.pop();

        int data2 = pq.top();
        pq.pop();

        pq.push(data1 + data2);
        ans += data1 + data2;
    }

    cout << ans << '\n';

    return 0;
}

// 1715_카드정렬하기
// 그리디
// 우선순위큐
// 최대 or 최소 를 구하는 문제라면 그리디 생각해보기